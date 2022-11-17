const db = require("../database");

const account = {
  getById: function (id, callback) {
    return db.query("select * from account where idaccount=?", [id], callback);
  },
  getAll: function (callback) {
    return db.query("select * from account", callback);
  },

  add: function (add_data, callback) {
    return db.query(
      "insert into account values(?,?,?,?)",
      [add_data.idaccount, add_date.cardnum, add_data.balance, add_data.credit],
      callback
    );
  },
  delete: function (id, callback) {
    return db.query("delete from account where idaccount=?", [id], callback);
  },
  update: function (id, update_data, callback) {
    return db.query(
      "update grade set cardnum=?,balance=?,credit=? where idaccount=?",
      [add_date.cardnum, add_data.balance, add_data.credit],
      callback
    );
  },

  checkBalance: function (idaccount, callback) {
    return db.query(
      "select balance,credit from account where idaccount=?",
      idaccount,
      callback
    );
  },

  withdraw: function (idaccount, amount, callback) {
    return db.query(
      "UPDATE account SET balance = balance-? WHERE idaccount=?",
      [amount, idaccount],
      callback
    );
  },

  create: function (idaccount, cardnum, balance, credit) {
    return db.query("insert into account values(?,?,?,?)", [
      idaccount,
      cardnum,
      balance,
      credit,
    ]);
  },
};

module.exports = account;
