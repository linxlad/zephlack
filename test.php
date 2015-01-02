<?php

try {
    $client = new Zephlack\Client('tracksy', 'CnTcDCW4CGWwCMyKub41aL1s');
} catch (Exception $e) {
    echo $e->getMessage();
}

echo $client->getUrl(). ':'. $client->getToken();

$arr = [1 => 'a', 2 => 'b'];

$result = $client->encode($arr);

$message = new Zephlack\Message\Message('Hello world');