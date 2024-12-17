FROM ubuntu:20.04

RUN apt-get update && apt-get intsall -y \
build-essential \
cmake \
libreadline-dev \
&& rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .

RUN mkdir -p build 
RUN cmake -S . -B build
RUN cmake --build build

CMD ["./build/myshell"]