/* Python DTrace provider */

provider cpython {
    probe function__entry(const char *, const char *, int);
    probe function__return(const char *, const char *, int);
    probe instance__new__start(const char *, const char *);
    probe instance__new__done(const char *, const char *);
    probe instance__delete__start(const char *, const char *);
    probe instance__delete__done(const char *, const char *);
    probe line(const char *, const char *, int);
    probe gc__start(int);
    probe gc__done(long);
};

#pragma D attributes Evolving/Evolving/Common provider cpython provider
#pragma D attributes Evolving/Evolving/Common provider cpython module
#pragma D attributes Evolving/Evolving/Common provider cpython function
#pragma D attributes Evolving/Evolving/Common provider cpython name
#pragma D attributes Evolving/Evolving/Common provider cpython args
