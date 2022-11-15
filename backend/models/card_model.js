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

  checkLocked: function (cardnum) {
    return db.query("select islocked from card where cardnum=?", cardnum);
  },

  addFail: function (cardnum, callback) {
    return db.query(
      "update card set pin_tries=pin_tries+1 where cardnum=?",
      cardnum,
      callback
    );
  },
};
module.exports = card;
