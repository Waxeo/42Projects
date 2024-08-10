FROM debian:bullseye

EXPOSE 443

RUN		apt update && apt install -y --no-install-recommends --no-install-suggests \
		nginx \
		openssl && \
		rm -rf /var/lib/apt/lists/*


RUN mkdir -p /etc/nginx/ssl

RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=mgauvrit.42.fr/UID=mgauvrit"

RUN mkdir -p /var/run/nginx

COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY	conf/server.conf	/etc/nginx/conf.d/

RUN		echo "\tserver name mgauvrit.42.fr;\n\
			\tssl_certificate /etc/nginx/ssl/inception.crt;\n\
			\tssl_certificate_key /etc/nginx/ssl/inception.key;\n\
			}" >> /etc/nginx/conf.d/server.conf

RUN		mkdir -p /var/www/

RUN chown -R www-data:www-data /var/www/

CMD [ "nginx", "-g", "daemon off;" ]