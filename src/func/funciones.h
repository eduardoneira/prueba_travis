#include <iostream>

#include "rocksdb/db.h"
#include "rocksdb/slice.h"
#include "rocksdb/options.h"

using namespace rocksdb;
const std::string kDBPath="/tmp/";

bool openDB(Options op,DB* db){
  std::cout << "Abriendo DB" << std::endl;

  op.create_if_missing = true;

  Status s = DB::Open(op, kDBPath, &db);

  // create column family
  ColumnFamilyHandle* cf;
  s = db->CreateColumnFamily(ColumnFamilyOptions(), "new_cf", &cf);

  // close DB
  delete cf;
  delete db;
  
  return s.ok();
}
