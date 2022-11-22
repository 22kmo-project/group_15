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
      [add_data.idaccount, add_data.cardnum, add_data.balance, add_data.credit],
      callback
    );
  },

  delete: function (id, callback) {
    return db.query("delete from account where idaccount=?", [id], callback);
  },

  update: function (id, update_data, callback) {
    return db.query(
      "update grade set cardnum=?,balance=?,credit=? where idaccount=?",
      [add_data.cardnum, add_data.balance, add_data.credit],
      callback
    );
  },
  getAccount: function (cardnum, callback) {
    return db.query("select*from account where cardnum=?", cardnum, callback);
  },
};

module.exports = account;
