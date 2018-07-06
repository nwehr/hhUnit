FROM hhvm/hhvm

COPY src /usr/local/nunit/src
COPY test /usr/local/nunit/test
COPY bin/nunit /usr/local/bin/nunit

RUN chmod +x /usr/local/bin/nunit && mkdir -p /unit-tests

ENTRYPOINT ["/usr/local/bin/nunit", "/unit-tests"] 