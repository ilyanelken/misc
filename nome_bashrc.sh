#!/bin/bash

IP_PREFIX="10.0"

# Generate IP address
HOST=$(hostname)
HOST_NUM=${HOST#no}

if (( $HOST_NUM > 255 )) ; then
	HOST_NUM_LSB=255
	HOST_NUM_MSB=$((HOST_NUM - 255))
else
	HOST_NUM_LSB=$HOST_NUM
	HOST_NUM_MSB=0
fi

IP=$IP_PREFIX.$HOST_NUM_MSB.$HOST_NUM_LSB

# Configure IPoIB network interface
INTERFACE="ib0"

ifconfig $INTERFACE $IP netmask 255.255.0.0 > /dev/null
if [[ $? != 0 ]] ; then
	echo "ERROR: unable to configure $INTERFACE interface with $IP ip"
fi

# Increase kernel neighbour cache capacity
CACHE_SIZE=49152

sysctl -w net.ipv4.neigh.default.gc_thresh3=$CACHE_SIZE > /dev/null
if [[ $? != 0 ]] ; then
	echo "ERROR: unable to set neigh cache size to $CACHE_SIZE"
fi

