const express = require("express");
const router = express.Router();
const bcrypt = require("bcryptjs");
const jwt = require("jsonwebtoken");
const dotenv = require("dotenv");
const card = require("../models/card_model");

router.post("/", function (request, response) {
  if (request.body.cardnum && request.body.cardpin) {
    const cardnum = request.body.cardnum;
    const cardpin = request.body.cardpin;
    card.checkCardPin(cardnum, function (dbError, dbResult) {
      if (dbError) {
        response.json(dbError.errno);
      }
      //tarkistetaan onko kortti lukittu
      else if ((card.checkLocked = 1)) {
        response.json({ body: "card locked" });
      } else {
        if (dbResult.length > 0) {
          bcrypt.compare(
            cardpin,
            dbResult[0].cardpin,
            function (err, compareResult) {
              if (compareResult) {
                console.log("success");
                const token = generateAccessToken({ card: cardnum });
                response.send(token);
              } else {
                console.log("wrong pin");
                response.send(false);
                //väärän pin koodin jälkeen kirjataan ylös väärä yritys
                card.addFail(cardnum, function (dbError, dbResult) {
                  console.log("added fail to pin tries");
                });
              }
            }
          );
        } else {
          console.log("card does not exists");
          response.send(false);
        }
      }
    });
  } else {
    console.log("cardnum or cardpin missing");
    response.send(false);
  }
});

function generateAccessToken(card) {
  dotenv.config();
  return jwt.sign(card, process.env.MY_TOKEN, { expiresIn: "180s" });
}
