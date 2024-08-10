#!/bin/sh
npm cache clean --force
yarn cache clean
docker ps -q | xargs docker stop
docker volume prune &&
docker system prune -af &&
docker image prune -af &&
docker system prune -af --volumes &&
docker system df