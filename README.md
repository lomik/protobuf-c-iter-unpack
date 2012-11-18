## Description

protobuf-c-iter-unpack - fast unpacker for [protobuf-c](http://code.google.com/p/protobuf-c/).

Focused on unpacking messages in the same pre-allocated buffer.

## Specification

* Uses protobuf-c structures
* Generates simple for read and use source code
* Supports all field types
* Does not check the required fields during the parse (as protobuf-c)
* Supports packed repeated data (as protobuf-c)
* Supports merge sub-messages (protobuf-c [not support](http://code.google.com/p/protobuf-c/issues/detail?id=91))
* Written for protobuf-c 0.15

## Usage

You must have installed google protobuf library (and python binding)

Generate source and headers:
```sh
# create test.pb-c.h and test.pb-c.c
protoc-c --c_out=. test.proto
# create test_pb2.py for protobuf-c-iter-unpack
protoc --python_out=. test.proto
# create test.pb-iter.h and test.pb-iter.c
protobuf-c-iter-unpack.py test_pb2.py
# test_pb2.py no longer needed
rm test_pb2.py
```

Example:
```c
// pre-allocate buffer
uint8_t iter_msg_buffer[65535];
size_t iter_msg_buffer_size = sizeof(iter_msg_buffer);

TestMessage* msg = (TestMessage*)iter_msg_buffer;

int ret = test_message__iter_unpack(input_buffer, input_buffer_length, iter_msg_buffer, iter_msg_buffer_size);

if (ret == -2) {
  printf("iter_msg_buffer to small for unpack\n");
} else if (ret == -1) {
  printf("can't unpack message from input_buffer\n");
} else if (ret < 0) {
  printf("unknown error: %d\n", ret);
} else {
  printf("message unpacked sucessful. used %d bytes of iter_msg_buffer\n", ret);
  // handle message
  // ...
}

```

## Benchmark

Tested on:
CentOS 6.3 x86-64, 

Competitors:
* 1. protobuf-c with default malloc allocator
* 2. protobuf-c with fastest linear allocator, don't execute free_unpacked method.
* 3. original google c++ parser
* 4. protobuf-c-iter-unpack

Test data:
* 1. message with 10 fields of uint32 type
* 2. 10 x fixed32
* 3. 10 x fixed64
* 4. 10 x string
* 5. [openx test message](http://bid.openx.net/ssrtb_tester)

Result in millions of unpacking per second. Higher is better.

| test    | 1. c, malloc | 2. c, linear | 3. c++, google | 4. iter-unpack |
|:--------|-------------:|-------------:|---------------:|---------------:|
| uint32  | This         |        This |     This     |
| fixed32 | column       |      column |    column    |
| fixed64 | will       |        will |     will     |
| string  | be         |          be |      be      |
| openx   | left       |       right |    center    |
