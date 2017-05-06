#!/bin/bash

for i in {1..12..1}
    do
    mkdir johnathanLeeLab$i
    mv johnathanLeeLab$i.zip johnathanLeeLab$i/
    cd johnathanLeeLab$i
    unzip -j *.zip
    cd ..
done
