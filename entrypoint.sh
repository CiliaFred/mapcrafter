#!/bin/sh
mkdir /tmp/input
mkdir /tmp/output

echo "Get inputs"
gsutil -m -q cp -R gs://minecraft-save-2022/HelloWorld/* /tmp/input/

echo "Process map"
/usr/local/bin/mapcrafter -c map.conf -j 8
rm -fr /tmp/input

echo "Save map"
gsutil -o "GSUtil:max_upload_compression_buffer_size=16G" -h "Cache-Control:no-store" -m -q cp -J -R /tmp/output/* gs://minecraft.cilia.paris/

echo "Clean storage"
rm -fr /tmp/output
