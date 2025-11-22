FROM debian:12

# Labels
LABEL org.opencontainers.image.authors="aimandebug"

WORKDIR /gat-dev

# Base programming tools
RUN apt update && apt -y upgrade && \
apt -y install gcc-arm-linux-gnueabihf qemu-user gdb-multiarch && \
apt clean && \
rm -fr /var/lib/apt/lists/*

ENTRYPOINT ["/bin/bash"]
