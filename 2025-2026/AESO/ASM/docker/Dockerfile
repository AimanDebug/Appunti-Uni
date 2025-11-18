FROM debian:12

# Labels
LABEL org.opencontainers.image.authors="AimanDebug"

WORKDIR /arm-dev

# Base programming tools
RUN apt update && apt -y upgrade && \
apt -y install gcc-arm-linux-gnueabihf qemu-user gdb-multiarch ssh && \
apt clean && \
rm -fr /var/lib/apt/lists/*

COPY entrypoint.sh .
RUN chmod +x entrypoint.sh

# Use env file for modified ones
ENV USERNAME=dev
ENV PASSWORD=changeme

ENTRYPOINT ["/arm-dev/entrypoint.sh"]
