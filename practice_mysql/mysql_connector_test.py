from mysql.connector import connect

cnx = connect(user="root", password="root", host="127.0.0.1", database="mydb")

cursor = cnx.cursor(buffered=True)

sql = 'UPDATE todos SET status = 1 where id >= 2'
cursor.execute(sql)

sql = 'SELECT * FROM todos'
cursor.execute(sql)

# DBを表示
rows = cursor.fetchall()
print(rows)

cnx.commit()  # これがないと反映されない

# 諸々閉じる
cursor.close()
cnx.close()
