#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test.pb-c.h"
#include "test.pb-iter.h"
#include "ssrtb_v6.pb-c.h"
#include "ssrtb_v6.pb-iter.h"
#include "test.h"


uint8_t iter_msg_buffer[50*1024];

int testTrue(int v, char* message) {
  if (v) {
    printf("%s ... ok\n", message);
    return 1;
  } else {
    printf("%s ... FAILED\n", message);
    return 0;
  }
}

#define types_clean_msg() types__init(types_msg)

#define types_pack_and_iter_unpack() \
  packed_size = types__pack(types_msg, pack_buffer);\
  unpack_result = types__iter_unpack(pack_buffer, packed_size, iter_msg_buffer, sizeof(iter_msg_buffer));

int test_types() {
  Types _types_msg;
  Types* types_msg = &_types_msg;

  Types *types_iter_msg = (Types*)iter_msg_buffer;
  uint8_t pack_buffer[50*1024];
  int packed_size;
  int unpack_result;

  // double
  types_clean_msg();
  types_msg->t_double = 134148.15123;
  types_msg->has_t_double = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->t_double==types_msg->t_double, "double positive value");

  types_clean_msg();
  types_msg->t_double = -64322758.12234;
  types_msg->has_t_double = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->t_double==types_msg->t_double, "double negative value");

  // float
  types_clean_msg();
  types_msg->t_float = 48.15;
  types_msg->has_t_float = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->t_float==types_msg->t_float, "float positive value");

  types_clean_msg();
  types_msg->t_float = -2758.12;
  types_msg->has_t_float = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->t_float==types_msg->t_float, "float negative value");

  // int32
  types_clean_msg();
  types_msg->t_int32 = 14142;
  types_msg->has_t_int32 = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->t_int32==types_msg->t_int32, "int32 positive value");

  types_clean_msg();
  types_msg->t_int32 = -14143;
  types_msg->has_t_int32 = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->t_int32==types_msg->t_int32, "int32 negative value");

  // int64
  types_clean_msg();
  types_msg->t_int64 = 4295067796;
  types_msg->has_t_int64 = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->t_int64==types_msg->t_int64, "int64 positive value");

  types_clean_msg();
  types_msg->t_int64 = -4295067796;
  types_msg->has_t_int64 = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->t_int64==types_msg->t_int64, "int64 negative value");

  // uint32
  types_clean_msg();
  types_msg->t_uint32 = 14142;
  types_msg->has_t_uint32 = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->t_uint32==types_msg->t_uint32, "uint32 value");

  // uint64
  types_clean_msg();
  types_msg->t_uint64 = 4295067796;
  types_msg->has_t_uint64 = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->t_uint64==types_msg->t_uint64, "uint64 value");

  // sint32
  types_clean_msg();
  types_msg->t_sint32 = 14142;
  types_msg->has_t_sint32 = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->t_sint32==types_msg->t_sint32, "sint32 positive value");

  types_clean_msg();
  types_msg->t_sint32 = -14143;
  types_msg->has_t_sint32 = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->t_sint32==types_msg->t_sint32, "sint32 negative value");

  // sint64
  types_clean_msg();
  types_msg->t_sint64 = 4295067796;
  types_msg->has_t_sint64 = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->t_sint64==types_msg->t_sint64, "sint64 positive value");

  types_clean_msg();
  types_msg->t_sint64 = -4295067796;
  types_msg->has_t_sint64 = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->t_sint64==types_msg->t_sint64, "sint64 negative value");

  // fixed32
  types_clean_msg();
  types_msg->t_fixed32 = 14142;
  types_msg->has_t_fixed32 = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->t_fixed32==types_msg->t_fixed32, "fixed32 value");

  // fixed64
  types_clean_msg();
  types_msg->t_fixed64 = 4295067796;
  types_msg->has_t_fixed64 = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->t_fixed64==types_msg->t_fixed64, "fixed64 value");

  // sfixed32
  types_clean_msg();
  types_msg->t_sfixed32 = 14142;
  types_msg->has_t_sfixed32 = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->t_sfixed32==types_msg->t_sfixed32, "sfixed32 positive value");

  types_clean_msg();
  types_msg->t_sfixed32 = -14142;
  types_msg->has_t_sfixed32 = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->t_sfixed32==types_msg->t_sfixed32, "sfixed32 negative value");

  // sfixed64
  types_clean_msg();
  types_msg->t_sfixed64 = 4295067796;
  types_msg->has_t_sfixed64 = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->t_sfixed64==types_msg->t_sfixed64, "sfixed64 positive value");

  types_clean_msg();
  types_msg->t_sfixed64 = -4295067796;
  types_msg->has_t_sfixed64 = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->t_sfixed64==types_msg->t_sfixed64, "sfixed64 negative value");

  // bool
  types_clean_msg();
  types_msg->t_bool = 1;
  types_msg->has_t_bool = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->t_bool==types_msg->t_bool, "bool true");

  types_clean_msg();
  types_msg->t_bool = 0;
  types_msg->has_t_bool = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->t_bool==types_msg->t_bool, "bool false");

  // enum
  types_clean_msg();
  types_msg->t_enum = TYPES__CHOICES__c1;
  types_msg->has_t_enum = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->has_t_enum, "has enum (choice 1)");
  testTrue(types_iter_msg->t_enum==types_msg->t_enum, "enum choice 1");

  types_clean_msg();
  types_msg->t_enum = TYPES__CHOICES__c2;
  types_msg->has_t_enum = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->has_t_enum, "has enum (choice 2)");
  testTrue(types_iter_msg->t_enum==types_msg->t_enum, "enum choice 2");

  types_clean_msg();
  types_msg->t_enum = TYPES__CHOICES__c3;
  types_msg->has_t_enum = 1;
  types_pack_and_iter_unpack();
  testTrue(types_iter_msg->has_t_enum, "has enum (choice 3)");
  testTrue(types_iter_msg->t_enum==types_msg->t_enum, "enum choice 3");

  // string
  types_clean_msg();
  types_msg->t_string = "hello world";
  types_pack_and_iter_unpack();
  if (testTrue(types_iter_msg->t_string != NULL, "has string")) {
    testTrue(strcmp(types_iter_msg->t_string, types_msg->t_string)==0, "string value");
  }

  // bytes
  types_clean_msg();
  types_msg->has_t_bytes = 1;
  types_msg->t_bytes.len = 12;
  char* hw = "world hello";
  types_msg->t_bytes.data = (uint8_t*)hw;
  types_pack_and_iter_unpack();
  if (testTrue(types_iter_msg->has_t_bytes ==  types_msg->has_t_bytes, "has bytes")) {
    if (testTrue(types_iter_msg->t_bytes.len ==  types_msg->t_bytes.len, "bytes len")) {
      testTrue(memcmp(types_iter_msg->t_bytes.data, types_msg->t_bytes.data, types_msg->t_bytes.len) == 0, "bytes value");
    }
  }

  // submessage
  types_clean_msg();
  Types__SubMessage sub;
  types__sub_message__init(&sub);
  sub.has_t_submessage_uint32 = 1;
  sub.t_submessage_uint32 = 42;
  types_msg->t_submessage = &sub;
  types_pack_and_iter_unpack();
  if (testTrue(types_iter_msg->t_submessage!=NULL, "has submessage")) {
    if (testTrue(types_iter_msg->t_submessage->has_t_submessage_uint32, "submessage has uint32 field")) {
      testTrue(types_iter_msg->t_submessage->t_submessage_uint32==42, "submessage uint32 field value");
    }
  }

  // repeated uint32
  types_clean_msg();
  uint32_t repeated_data[5] = {42, 100500, 1024, 65000, 89555};
  types_msg->n_t_repeated_uint32 = 5;
  types_msg->t_repeated_uint32 = repeated_data;
  types_pack_and_iter_unpack();
  if (testTrue(types_iter_msg->n_t_repeated_uint32==5, "repeated uint32 size")) {
    testTrue(types_iter_msg->t_repeated_uint32[0]==42, "repeated uint32 item 0");
    testTrue(types_iter_msg->t_repeated_uint32[1]==100500, "repeated uint32 item 1");
    testTrue(types_iter_msg->t_repeated_uint32[4]==89555, "repeated uint32 item 4");
  }

  // repeated string
  types_clean_msg();
  types_msg->n_t_repeated_string = 2;
  types_msg->t_repeated_string = (char**)malloc(sizeof(char*)*2);
  types_msg->t_repeated_string[0] = "hello world";
  types_msg->t_repeated_string[1] = "42";
  types_pack_and_iter_unpack();
  free(types_msg->t_repeated_string);
  testTrue(types_iter_msg->n_t_repeated_string==2, "repeated string size");
  testTrue(strcmp(types_iter_msg->t_repeated_string[0], "hello world") == 0, "repeated string item 0");
  testTrue(strcmp(types_iter_msg->t_repeated_string[1], "42") == 0, "repeated string item 1");


  // repeated bytes
  types_clean_msg();
  types_msg->t_repeated_bytes = (ProtobufCBinaryData*)malloc(sizeof(ProtobufCBinaryData)*2);
  types_msg->n_t_repeated_bytes = 2;

  types_msg->t_repeated_bytes[0].len = sizeof(BINARY_HELLO_WORLD);
  types_msg->t_repeated_bytes[0].data = malloc(sizeof(BINARY_HELLO_WORLD)*sizeof(uint8_t));
  memcpy(types_msg->t_repeated_bytes[0].data, BINARY_HELLO_WORLD, sizeof(BINARY_HELLO_WORLD));

  types_msg->t_repeated_bytes[1].len = sizeof(BINARY_42);
  types_msg->t_repeated_bytes[1].data = malloc(sizeof(BINARY_42)*sizeof(uint8_t));
  memcpy(types_msg->t_repeated_bytes[1].data, BINARY_42, sizeof(BINARY_42));

  types_pack_and_iter_unpack();
  free(types_msg->t_repeated_bytes[0].data);
  free(types_msg->t_repeated_bytes[1].data);
  free(types_msg->t_repeated_bytes);

  testTrue(unpack_result > 2, "unpack repeated bytes");
  testTrue(types_iter_msg->n_t_repeated_bytes==2, "repeated bytes count");
  testTrue(types_iter_msg->t_repeated_bytes[0].len==11, "repeated bytes [0] len");
  testTrue(types_iter_msg->t_repeated_bytes[1].len==2, "repeated bytes [1] len");
  testTrue(memcmp(types_iter_msg->t_repeated_bytes[0].data, BINARY_HELLO_WORLD, 11) == 0, "repeated bytes [0] value");
  testTrue(memcmp(types_iter_msg->t_repeated_bytes[1].data, BINARY_42, 2) == 0, "repeated bytes [1] value");



  // packed fields unpack
  PackedField* c_packed = packed_field__unpack(NULL, sizeof(REPEATED_PACKED), REPEATED_PACKED);
  PackedField* f_packed = (PackedField*)iter_msg_buffer;
  unpack_result = packed_field__iter_unpack(REPEATED_PACKED, sizeof(REPEATED_PACKED), iter_msg_buffer, sizeof(iter_msg_buffer));
  testTrue(unpack_result>=0, "unpack repeated packed");
  if (testTrue( (f_packed->n_f1==6) && (f_packed->n_f1==c_packed->n_f1), "packed repeated len")) {
    testTrue(f_packed->f1[0]==10, "packed repeated item 0");
    testTrue(f_packed->f1[5]==408, "packed repeated item 5");
  }

  MergeTest* c_merge = merge_test__unpack(NULL, sizeof(MERGE_TEST), MERGE_TEST);
  MergeTest* f_merge = (MergeTest*)iter_msg_buffer;
  unpack_result = merge_test__iter_unpack(MERGE_TEST, sizeof(MERGE_TEST), iter_msg_buffer, sizeof(iter_msg_buffer));

  testTrue( (c_merge->submsg->f1==777) && (c_merge->submsg->f2==0), "protobuf-c not merged submessage");
  testTrue( (f_merge->submsg->f1==777) && (f_merge->submsg->f2==42), "protobuf-c-iter-unpack merged submessage");

  return 1;
}

int test_openx() {
  BidRequest* c = bid_request__unpack(NULL, sizeof(OPENX_1), OPENX_1);
  BidRequest* f = (BidRequest*)iter_msg_buffer;
  bid_request__iter_unpack(OPENX_1, sizeof(OPENX_1), iter_msg_buffer, sizeof(iter_msg_buffer));

  testTrue(c->matching_ad_ids[0]->campaign_id==f->matching_ad_ids[0]->campaign_id, "OpenX equal Matching Ad Id");

  bid_request__free_unpacked(c, NULL);

  return 1;
}

int test_validation() {
  int unpack_result = 0;
  RequiredField2* c_req = required_field2__unpack(NULL, sizeof(F1V10), F1V10);
  unpack_result = required_field2__iter_unpack(F1V10, sizeof(F1V10), iter_msg_buffer, sizeof(iter_msg_buffer));
  testTrue((c_req != NULL) && (unpack_result >= 0),"don't validate required");

  StringField* c_string = string_field__unpack(NULL, sizeof(ZERO_BYTE_STRING), ZERO_BYTE_STRING);
  StringField* f_string = (StringField*)iter_msg_buffer;
  unpack_result = string_field__iter_unpack(ZERO_BYTE_STRING,  sizeof(ZERO_BYTE_STRING),  iter_msg_buffer, sizeof(iter_msg_buffer));
  testTrue((f_string->f1 != NULL) && (strcmp(c_string->f1,f_string->f1)==0),"don't validate string");

  unpack_result = types__iter_unpack(NEGATIVE_LENGTH_STRING,  sizeof(NEGATIVE_LENGTH_STRING),  iter_msg_buffer, sizeof(iter_msg_buffer));

  testTrue(unpack_result == PROTOBUF_ITER_WRONG_MESSAGE, "string length overflow");

  return 1;
}

int main() {
  test_types();
  test_openx();
  test_validation();

  return 1;
}
