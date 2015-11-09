#include <cstdio>
#include <string>
#include <vector>

#include "rocksdb/db.h"
#include "rocksdb/slice.h"
#include "rocksdb/options.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "funciones.h"

TEST(DatabaseTest,crearDB){
  Options options;
  DB* db;
  EXPECT_TRUE(openDB(options,db));

}

int main(int argc, char** argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
