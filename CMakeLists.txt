cmake_minimum_required(VERSION 3.17)
project(MemStore)

set(CMAKE_CXX_STANDARD 14)



add_executable(
        MemStore main.cpp
        engine/Buffer.cpp engine/Buffer.h
        engine/BufferPool.cpp engine/BufferPool.h
        engine/EngineLogger.cpp engine/EngineLogger.h
        Util/HashCodeUtil.cpp Util/HashCodeUtil.h
        engine/DataType/BasicDataType.cpp engine/DataType/BasicDataType.h
        engine/Semaphore.h engine/Semaphore.cpp
        engine/MemTable.cpp engine/MemTable.h)