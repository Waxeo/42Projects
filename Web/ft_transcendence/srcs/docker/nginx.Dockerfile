FROM nginx:latest

RUN rm /etc/nginx/conf.d/default.conf

RUN		apt update && apt install -y --no-install-recommends --no-install-suggests \
		openssl && \
		rm -rf /var/lib/apt/lists/*

RUN mkdir -p /etc/nginx/ssl && \
	openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
	-out /etc/nginx/ssl/nginx.crt \
	-keyout /etc/nginx/ssl/nginx.key \
	-subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=localhost"


COPY ../docker/default.conf /etc/nginx/conf.d/default.conf
COPY ../docker/nginx.conf /etc/nginx/nginx.conf


COPY ../frontend /etc/frontend
RUN chown -R nginx:nginx /etc/frontend

EXPOSE 3000

CMD ["nginx", "-g", "daemon off;"]
