FROM debian:bullseye

EXPOSE 3306

RUN	apt update && \
	apt install -y --no-install-recommends --no-install-suggests \
	mariadb-server && \
	rm -rf /var/lib/apt/lists/*


COPY conf/50-server.cnf	/etc/mysql/mariadb.conf.d/

COPY ./tools/database_creat.sh /database_creat.sh

RUN chmod +x database_creat.sh

CMD ["/database_creat.sh", "mysqld_safe"].