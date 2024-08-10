FROM debian:bullseye

EXPOSE 9000

RUN apt update && apt install --no-install-recommends --no-install-suggests -y \
	ca-certificates \
	php7.4-fpm \
	php7.4-mysql \
	wget \
	tar && \
	rm -rf /var/lib/apt/lists/*

COPY conf/www.conf /etc/php/7.4/fpm/pool.d/

RUN sed -i 's/;cgi.fix_pathinfo=1/cgi.fix_pathinfo=0/g' /etc/php/7.4/fpm/php.ini && \
	sed -i "s/listen = \/run\/php\/php$PHP_VERSION_ENV-fpm.sock/listen = 9000/g" /etc/php/7.4/fpm/pool.d/www.conf && \
	sed -i 's/;listen.mode = 0660/listen.mode = 0660/g' /etc/php/7.4/fpm/pool.d/www.conf && \
	sed -i 's/;daemonize = yes/daemonize = no/g' /etc/php/7.4/fpm/pool.d/www.conf

RUN wget --no-check-certificate https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin/wp

RUN mkdir -p /run/php/ && \
	mkdir -p /var/run/php/ && \
	mkdir -p /var/www/inception/

RUN chown -R www-data:www-data /var/www/inception/

COPY conf/wp-config.php /tmp/

COPY /tools/auto_config.sh /auto_config.sh

RUN chmod +x /auto_config.sh

CMD ["/auto_config.sh", "php-fpm7.4", "--nodaemonize"]