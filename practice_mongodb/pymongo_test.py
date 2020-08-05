from pymongo import MongoClient
from bson.objectid import ObjectId
import datetime


class TestMongo(object):
    def __init__(self):
        self.client = MongoClient("mongodb://normal_user:normal_password@127.0.0.1:27018/test_database")
        self.db = self.client["test_database"]

    def add_one(self):
        post = {
            "title": "ハリネズミ",
            "content": "ハリネズミ可愛い",
            "created_at": datetime.datetime.now()
        }
        return self.db.test.insert_one(post)

    def get_one(self):
        return self.db.test.find_one()

    def get_from_oid(self,oid):
        return self.db.test.find_one({"_id":ObjectId(oid)})

    def update(self):
        rest = self.db.test.update_one({"title":"ハリネズミ"},{"$set":{"content":"カワウソかわうそう"}})
        return rest

    def update_many(self):
        rest = self.db.test.update_many({},{"$set":{"created_at":datetime.datetime.now()}})
        return rest

    def delete(self):
        rest = self.db.test.delete_one({"content":"カワウソかわうそう"})
        return rest


def main():
    obj = TestMongo()
    rest = obj.add_one()
    #rest = obj.get_one()
    #rest = obj.get_from_oid("5f05921d9f5f1d74f08a38c5")
    #rest = obj.update()
    #rest = obj.update_many()
    #print(rest.matched_count)
    #rest = obj.delete()
    print(rest)

if __name__ == '__main__':
    main()
