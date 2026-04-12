FROM ubuntu:24.04 AS base

ARG BINUTILS_VERSION=2.35.2
ARG GCC_VERSION=14.3.0

ENV DEBIAN_FRONTEND=noninteractive \
    TARGET=score-elf \
    PREFIX=/opt/score-toolchain \
    SRCROOT=/opt/src \
    PATH=/opt/score-toolchain/bin:${PATH} \
    BINUTILS_VERSION=${BINUTILS_VERSION} \
    GCC_VERSION=${GCC_VERSION}

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

FROM base AS builder

WORKDIR /build

COPY patches /patches
COPY newlib ${SRCROOT}/newlib

RUN set -eux; \
    curl -L --fail "https://ftp.gnu.org/gnu/binutils/binutils-${BINUTILS_VERSION}.tar.bz2" -o binutils.tar.bz2; \
    curl -L --fail "https://ftp.gnu.org/gnu/gcc/gcc-${GCC_VERSION}/gcc-${GCC_VERSION}.tar.xz" -o gcc.tar.xz; \
    tar xf binutils.tar.bz2; \
    tar xf gcc.tar.xz; \
    cd "/build/gcc-${GCC_VERSION}"; \
    ./contrib/download_prerequisites

RUN set -eux; \
    cd "binutils-${BINUTILS_VERSION}"; \
    patch --dry-run -p0 < /patches/binutils-patch.diff; \
    patch -p0 < /patches/binutils-patch.diff

RUN set -eux; \
    cd "gcc-${GCC_VERSION}"; \
    patch --dry-run -p0 < /patches/gcc-patch.diff; \
    patch -p0 < /patches/gcc-patch.diff; \
    grep -n "score-\\*-elf" gcc/config.gcc; \
    test -f gcc/config/score/score.cc; \
    grep -n "score-\\*-elf" libgcc/config.host

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
        --disable-libstdcxx \
        --enable-languages=c,c++ \
        --with-gnu-as \
        --with-gnu-ld; \
    make -j"$(nproc)" all-gcc all-target-libgcc; \
    make install-gcc install-target-libgcc

RUN set -eux; \
    cd "${SRCROOT}/newlib"; \
    if [ -f configure.ac ] || [ -f configure.in ]; then autoreconf -fi || true; fi; \
    mkdir -p /build/build-newlib; \
    cd /build/build-newlib; \
    "${SRCROOT}/newlib/configure" \
        --target="${TARGET}" \
        --prefix="${PREFIX}" \
        --disable-multilib; \
    make -j"$(nproc)"; \
    make install

RUN set -eux; \
    mkdir -p "${SRCROOT}"; \
    mv "/build/binutils-${BINUTILS_VERSION}" "${SRCROOT}/"; \
    mv "/build/gcc-${GCC_VERSION}" "${SRCROOT}/"

FROM base

COPY --from=builder /opt/score-toolchain /opt/score-toolchain
COPY --from=builder /opt/src /opt/src

WORKDIR /workspace
CMD ["/bin/bash"]