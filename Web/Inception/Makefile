all: up

up:
	docker-compose -f srcs/docker-compose.yml up --build

stop:
	docker-compose -f srcs/docker-compose.yml stop

down:
	docker-compose -f srcs/docker-compose.yml down

start:
	docker-compose -f srcs/docker-compose.yml start

.PHONY: up stop down start