AM_CPPFLAGS=-O2 -g3 -Wall

noinst_PROGRAMS = test benchmark benchmark_cpp

test_SOURCES = test.pb-c.c ssrtb_v6.pb-c.c test.pb-iter.c ssrtb_v6.pb-iter.c test.c
test_LDFLAGS = -lprotobuf-c

benchmark_SOURCES = test.pb-c.c ssrtb_v6.pb-c.c test.pb-iter.c ssrtb_v6.pb-iter.c benchmark.c
benchmark_LDFLAGS = -lprotobuf-c

benchmark_cpp_SOURCES = test.pb.cc ssrtb_v6.pb.cc benchmark_cpp.cc
benchmark_cpp_LDFLAGS = -lprotobuf -lpthread

test.pb-c.c: test.proto
	protoc-c --c_out=. test.proto
test_pb2.py: test.proto
	protoc --python_out=. test.proto
test.pb-iter.c: test_pb2.py
	python ../../protobuf-c-iter-unpack.py test_pb2.py
test.pb.cc: test.proto
	protoc --cpp_out=. test.proto

ssrtb_v6.pb-c.c: ssrtb_v6.proto
	protoc-c --c_out=. ssrtb_v6.proto
ssrtb_v6_pb2.py: ssrtb_v6.proto
	protoc --python_out=. ssrtb_v6.proto
ssrtb_v6.pb-iter.c: ssrtb_v6_pb2.py
	python ../../protobuf-c-iter-unpack.py ssrtb_v6_pb2.py
ssrtb_v6.pb.cc: ssrtb_v6.proto
	protoc --cpp_out=. ssrtb_v6.proto

