FROM hhvm/hhvm

COPY src /usr/local/nunit/src
COPY test /usr/local/nunit/test
COPY bin/nunit /usr/local/bin/nunit

RUN chmod +x /usr/local/bin/nunit

CMD /usr/local/bin/nunit
