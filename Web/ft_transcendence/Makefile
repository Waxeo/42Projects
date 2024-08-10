all : up

up : 
	docker compose -f ./srcs/docker-compose.yml up --build

dev :
	docker compose -f ./srcs/docker-compose.dev.yml up --build

down : 
	docker-compose -f ./srcs/docker-compose.yml down

stop : 
	docker-compose -f ./srcs/docker-compose.yml stop

start : 
	docker-compose -f ./srcs/docker-compose.yml start

re : down up


.PHONY : up down stop start