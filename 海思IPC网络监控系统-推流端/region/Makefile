include ../Makefile.param

# 查找当前目录下的所有 .cpp 文件
SMP_SRCS := $(wildcard *.cpp)

# 生成的目标文件名（根据源文件名生成）
TARGET := $(SMP_SRCS:%.cpp=%)

TARGET_PATH := $(PWD)

# 使用 g++ 进行编译
CC := g++

# compile linux or HuaweiLite
include $(PWD)/../$(ARM_ARCH)_$(OSTYPE).mak