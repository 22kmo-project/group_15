const db = require("../database");
const bcrypt = require("bcryptjs");

const saltRounds = 10;

const card = {
  checkCardPin: function (cardnum, callback) {
    return db.query(
      "select cardpin from card where cardnum=?",
      cardnum,
      callback
    );
  },

  checkLocked: function (cardnum, callback) {
    return db.query(
      "select pin_tries from card where cardnum=?",
      cardnum,
      callback
    );
  },

  add: function (cardnum, cardpin, iduser, iscredit) {
    bcrypt.hash(cardpin, saltRounds, function (err, cardpin) {
      console.log(cardnum, cardpin, iduser, iscredit);
      return db.query("insert into card values(?,?,?,?,0,0)", [
        cardnum,
        cardpin,
        iduser,
        iscredit,
      ]);
    });
  },

  addFail: function (cardnum, callback) {
    return db.query(
      "update card set pin_tries=pin_tries+1 where cardnum=?",
      cardnum,
      callback
    );
  },
  resetFail: function (cardnum, callback) {
    return db.query(
      "update card set pin_tries=0 where cardnum=?",
      cardnum,
      callback
    );
  },
};
module.exports = card;
