var users = [
  {
    user: "normal_user",
    pwd: "normal_password",
    roles: [
      {
        role: "dbOwner",
        db: "test_database"
      }
    ]
  }
];

for (var i = 0, length = users.length; i < length; ++i) {
  db.createUser(users[i]);
}
