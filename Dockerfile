FROM hhvm/hhvm

COPY src /usr/local/hUnit/src
COPY bin/hUnit /usr/local/bin/hUnit

RUN chmod +x /usr/local/bin/hUnit && mkdir -p /usr/local/tests

ENTRYPOINT ["/usr/local/bin/hUnit", "/usr/local/tests"] 