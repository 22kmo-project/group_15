const db = require("../database");

const account = {
  add: function (idaccount, cardnum, balance, credit) {
    console.log();
    return db.query("insert into account values(?,11111,?,?,?)", [
      idaccount,
      cardnum,
      balance,
      credit,
    ]);
  },
};

module.exports = account;
