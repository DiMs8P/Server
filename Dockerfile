FROM ubuntu:latest
LABEL authors="dims"

RUN apt update && apt install -y g++ make

COPY . /app

WORKDIR /app
     
RUN g++ -o main main.cpp
CMD ["./main"]