#############
EFD SAL Kafka 
#############

Overview
^^^^^^^^
In some special occasions a component may be present at the summit but still in early stages of integration and verification.
In these conditions it may happen that the responsible software engineer needs to perform rapid changes to the component interface and/or software that are not compatible with the currently running production environment.

In order to avoid conflicts with the running systems, engineers can run their system isolated from the rest of the system by use of a different DDS domain.
Still, scientists and engineers may be interested in having the data produced by the component ingested into the EFD for later analysis.
In order to support this activities it is possible to run alternative kafka producers specially tailored for the running activity.

This procedure details how to provision a SAL Kafka producers on non-production (non-zero indexed) DDS domains to support development activities at the summit.

.. warning:: All of these procedures have the potential to inflict serious instablity on the summit stream of data to the EFD.
             These procedures must be executed with the utmost caution and in some cases should be used as a last resort.
             Consult your component's user guide first.


Pre-requisites
^^^^^^^^^^^^^^
* Determine which components are involved in the test
* Make sure components are **not** running in the production domain.
* :doc:`Announce your intentions in the appropriate channels </Operational-Procedures-Tutorials/announce-component-usage>`
* SSH access to azar2.cp.lsst.org node
* Docker permission in azar2

Responsibilities
^^^^^^^^^^^^^^^^
* Software Engineer

Procedure
^^^^^^^^^

Check that Kafka producers are running
--------------------------------------

.. prompt:: bash

    docker ps
    docker logs {name_of_container} # i.e. salkafka-m2

A normal result will look like this (from salkafka-m2)

.. code::

    salkafka-m2         | application DDS read queue is filling: 24 of 100 elements
    salkafka-m2         | rotation DDS read queue is filling: 21 of 100 elements
    salkafka-m2         | actuators DDS read queue is filling: 23 of 100 elements
    salkafka-m2         | motors DDS read queue is filling: 21 of 100 elements
    salkafka-m2         | electrical DDS read queue is filling: 22 of 100 elements
    salkafka-m2         | actuators python read queue is filling: 23 of 100 elements
    salkafka-m2         | electrical python read queue is filling: 23 of 100 elements
    salkafka-m2         | application python read queue is filling: 23 of 100 elements
    salkafka-m2         | application python read queue is filling: 21 of 100 elements
    salkafka-m2         | motors python read queue is filling: 21 of 100 elements
    salkafka-m2         | electrical python read queue is filling: 21 of 100 elements
    salkafka-m2         | rotation python read queue is filling: 22 of 100 elements
    salkafka-m2         | application DDS read queue is filling: 21 of 100 elements
    salkafka-m2         | actuators DDS read queue is filling: 23 of 100 elements
    salkafka-m2         | rotation DDS read queue is filling: 21 of 100 elements
    salkafka-m2         | motors DDS read queue is filling: 21 of 100 elements
    salkafka-m2         | electrical DDS read queue is filling: 24 of 100 elements
    salkafka-m2         | electrical DDS read queue is filling: 21 of 100 elements
    salkafka-m2         | actuators python read queue is filling: 22 of 100 elements
    salkafka-m2         | application DDS read queue is filling: 24 of 100 elements
    salkafka-m2         | motors python read queue is filling: 21 of 100 elements
    salkafka-m2         | electrical python read queue is filling: 21 of 100 elements
    salkafka-m2         | application python read queue is filling: 23 of 100 elements
    salkafka-m2         | application python read queue is filling: 21 of 100 elements
    salkafka-m2         | rotation python read queue is filling: 21 of 100 elements
    salkafka-m2         | electrical python read queue is filling: 23 of 100 elements


Add to the list of CSCs for the salkafka producers
--------------------------------------------------

.. prompt:: bash

    cd /deploy-lsst/docker-compose-ops/kafka_writers
    # edit docker-compose.yaml

Under salkafka-{system} service, add the component you wish to add by appending the name to the CSC_LIST field under environment.

.. prompt:: bash

    docker-compose up -d salkafka-{system} # i.e. salkafka-m2


Add to the list of CSCs for the salkafka producers while container is running
-----------------------------------------------------------------------------

.. warning:: This is potentially very dangerous and could lead to a loss of valuable EFD stream data, only do this when given the proper authority or never
             Follow the above procedure with the container off first, if possible

.. prompt:: bash

    docker ps
    docker attach salkafka-{component}
    # ctrl-c 
    echo $CSC_LIST
    # copy result
    CSC_LIST="{copied_result} {component_to_add}"
    run_salkafka_producer.py --broker $BROKER_IP:$BROKER_PORT \
    --registry $REGISTRY_ADDR \
    --partitions  $PARTITIONS \
    --loglevel $LOG_LEVEL \
    --replication-factor $REPLICATION \
    --wait-ack $WAIT_ACK \
    $CSC_LIST


Verification
^^^^^^^^^^^^
TBD

Troubleshooting
^^^^^^^^^^^^^^^
TBD
