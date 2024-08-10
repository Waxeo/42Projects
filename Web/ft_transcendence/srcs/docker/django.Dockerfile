FROM python:3.12

RUN apt-get update \
	&& apt-get install -y --no-install-recommends \
		postgresql-client \
		netcat-traditional \
		dumb-init \
	&& rm -rf /var/lib/apt/lists/*

WORKDIR /django

COPY ../django/requirements.txt ./

RUN pip install --no-cache-dir -r requirements.txt

COPY ../django .

EXPOSE 8000

COPY docker/start.sh /start.sh
RUN chmod +x /start.sh

ENTRYPOINT ["dumb-init", "/start.sh"]