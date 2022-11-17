const db = require("../database");

const log = {
  getById: function (idaccount, callback) {
    console.log();
    return db.query("select * from log where idaccount=?", idaccount, callback);
  },
  getAll: function (callback) {
    return db.query("select * from log", callback);
  },
  add: function (add_data, callback) {
    return db.query(
      "insert into log values(null,?,?,now())",
      [add_data.idaccount, add_data.withdraw_amount],
      callback
    );
  },
  delete: function (id, callback) {
    return db.query("delete from log where idlog=?", [id], callback);
  },
  update: function (id, update_data, callback) {
    return db.query(
      "update grade set idaccount=?,withdraw_amount=? where idlog=?",
      [add_data.idaccount, add_data.withdraw_amount],
      callback
    );
  },
};

module.exports = log;
