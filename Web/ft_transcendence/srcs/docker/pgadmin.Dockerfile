FROM	dpage/pgadmin4

COPY    --chown=pgadmin:5050 docker/servers.json .
COPY    --chown=pgadmin:5050 docker/pgpass .