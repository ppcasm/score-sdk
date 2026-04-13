FROM ubuntu:24.04 AS base

ARG BINUTILS_VERSION=2.35.2
ARG GCC_VERSION=14.3.0
ARG NEWLIB_VERSION=4.6.0.20260123

ENV DEBIAN_FRONTEND=noninteractive \
    TARGET=score-elf \
    PREFIX=/opt/score-toolchain \
    SRCROOT=/opt/src \
    BINUTILS_VERSION=${BINUTILS_VERSION} \
    GCC_VERSION=${GCC_VERSION} \
    NEWLIB_VERSION=${NEWLIB_VERSION} \
    PATH=/opt/score-toolchain/bin:/usr/local/bin:${PATH}

RUN apt-get update && apt-get install -y \
    build-essential \
    bison \
    flex \
    texinfo \
    gawk \
    patch \
    curl \
    ca-certificates \
    xz-utils \
    bzip2 \
    gzip \
    tar \
    make \
    cmake \
    ninja-build \
    python3 \
    git \
    autoconf2.69 \
    automake \
    libtool \
    m4 \
    perl \
    help2man \
    libgmp-dev \
    libmpfr-dev \
    libmpc-dev \
    libisl-dev \
    zlib1g-dev \
    file \
    pkg-config \
    rsync \
    vim \
    less \
 && rm -rf /var/lib/apt/lists/*

# Force unversioned autotools commands to use 2.69.
RUN ln -sf /usr/bin/autoconf2.69 /usr/local/bin/autoconf \
 && ln -sf /usr/bin/autoheader2.69 /usr/local/bin/autoheader \
 && ln -sf /usr/bin/autoreconf2.69 /usr/local/bin/autoreconf \
 && ln -sf /usr/bin/autoscan2.69 /usr/local/bin/autoscan \
 && ln -sf /usr/bin/autoupdate2.69 /usr/local/bin/autoupdate \
 && autoconf --version \
 && autoreconf --version

FROM base AS builder

WORKDIR /build

COPY patches /patches

RUN set -eux; \
    curl -L --fail "https://ftp.gnu.org/gnu/binutils/binutils-${BINUTILS_VERSION}.tar.bz2" -o binutils.tar.bz2; \
    curl -L --fail "https://ftp.gnu.org/gnu/gcc/gcc-${GCC_VERSION}/gcc-${GCC_VERSION}.tar.xz" -o gcc.tar.xz; \
    curl -L --fail "https://sourceware.org/pub/newlib/newlib-${NEWLIB_VERSION}.tar.gz" -o newlib.tar.gz; \
    tar xf binutils.tar.bz2; \
    tar xf gcc.tar.xz; \
    tar xf newlib.tar.gz; \
    cd "/build/gcc-${GCC_VERSION}"; \
    ./contrib/download_prerequisites

RUN set -eux; \
    cd "/build/binutils-${BINUTILS_VERSION}"; \
    patch --dry-run -p0 < /patches/binutils-patch.diff; \
    patch -p0 < /patches/binutils-patch.diff

RUN set -eux; \
    cd "/build/gcc-${GCC_VERSION}"; \
    patch --dry-run -p0 < /patches/gcc-patch.diff; \
    patch -p0 < /patches/gcc-patch.diff; \
    grep -n "score-\\*-elf" gcc/config.gcc; \
    test -f gcc/config/score/score.cc; \
    grep -n "score-\\*-elf" libgcc/config.host

RUN set -eux; \
    cd "/build/newlib-${NEWLIB_VERSION}"; \
    patch --dry-run -p1 < /patches/newlib-patch.diff; \
    patch -p1 < /patches/newlib-patch.diff; \
    cd newlib; \
    autoreconf -fi

RUN set -eux; \
    mkdir -p /build/build-binutils; \
    cd /build/build-binutils; \
    ../binutils-${BINUTILS_VERSION}/configure \
        --target="${TARGET}" \
        --prefix="${PREFIX}" \
        --disable-nls \
        --disable-multilib \
        --disable-static; \
    make -j"$(nproc)"; \
    make install

RUN set -eux; \
    mkdir -p /build/build-gcc-stage1; \
    cd /build/build-gcc-stage1; \
    ../gcc-${GCC_VERSION}/configure \
        --target="${TARGET}" \
        --prefix="${PREFIX}" \
        --without-headers \
        --with-newlib \
        --enable-obsolete \
        --disable-libada \
        --disable-libgomp \
        --disable-libmudflap \
        --disable-libssp \
        --disable-libatomic \
        --disable-libitm \
        --disable-libsanitizer \
        --disable-libquadmath \
        --disable-threads \
        --disable-multilib \
        --disable-target-zlib \
        --with-system-zlib \
        --disable-shared \
        --disable-nls \
        --disable-lto \
        --disable-libstdcxx-pch \
        --enable-languages=c,c++ \
        --with-gnu-as \
        --with-gnu-ld; \
    make -j"$(nproc)" all-gcc all-target-libgcc; \
    make install-gcc install-target-libgcc

RUN set -eux; \
    autoconf --version; \
    autoreconf --version; \
    rm -rf /build/build-newlib; \
    mkdir -p /build/build-newlib; \
    cd /build/build-newlib; \
    "/build/newlib-${NEWLIB_VERSION}/configure" \
        --target="${TARGET}" \
        --prefix="${PREFIX}" \
        --disable-multilib; \
    make -j"$(nproc)"; \
    make install

RUN set -eux; \
    mkdir -p "${SRCROOT}"; \
    mv "/build/binutils-${BINUTILS_VERSION}" "${SRCROOT}/"; \
    mv "/build/gcc-${GCC_VERSION}" "${SRCROOT}/"; \
    mv "/build/newlib-${NEWLIB_VERSION}" "${SRCROOT}/newlib"

FROM base

COPY --from=builder /opt/score-toolchain /opt/score-toolchain
COPY --from=builder /opt/src /opt/src

WORKDIR /workspace
CMD ["/bin/bash"]
