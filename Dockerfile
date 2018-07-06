FROM hhvm/hhvm

COPY src /usr/local/ndunit/src
COPY test /usr/local/ndunit/test
COPY bin/ndunit /usr/local/bin/ndunit

RUN chmod +x /usr/local/bin/ndunit && mkdir -p /unit-tests

ENTRYPOINT ["/usr/local/bin/ndunit", "/unit-tests"] 