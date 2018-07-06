FROM hhvm/hhvm

COPY src /usr/local/hUnit/src
COPY test /usr/local/hUnit/test
COPY bin/hUnit /usr/local/bin/hUnit

RUN chmod +x /usr/local/bin/hUnit && mkdir -p /unit-tests

ENTRYPOINT ["/usr/local/bin/hUnit", "/unit-tests"] 