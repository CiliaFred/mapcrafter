#
# Build Image
#

FROM gcr.io/google.com/cloudsdktool/google-cloud-cli:408.0.0-alpine as builder

# Add the git repo
ADD . /git/mapcrafter

RUN apk update

# Dependencies needed for building Mapcrafter
# (not sure how many of these are actually needed)
RUN apk add \
        cmake \
        gcc \
        make \
        g++ \
        zlib-dev \
        libpng-dev \
        libjpeg-turbo-dev \
    	# Alpine 3.16 Required
        #icu-data-full \
        boost-dev

# Build mapcrafter from source
RUN cd /git/mapcrafter && \
    mkdir build && cd build && \
    cmake .. && \
    make && \
    mkdir /tmp/mapcrafter && \
    make DESTDIR=/tmp/mapcrafter install

#
# Final Image
#

FROM gcr.io/google.com/cloudsdktool/google-cloud-cli:alpine

# Mapcrafter, built in previous stage
COPY --from=builder /tmp/mapcrafter/ /
COPY map.conf .

# Depedencies needed for running Mapcrafter
RUN apk add \
        libpng \
        libjpeg-turbo \
        boost \
        boost-iostreams \
        boost-system \
        boost-filesystem \
        boost-program_options \
        shadow

# Entrypoint
ADD entrypoint.sh /
ENTRYPOINT ["/entrypoint.sh"]
