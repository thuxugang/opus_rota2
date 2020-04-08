# OPUS-Rota2

## Dependency

For your convenience, the packages we used can be found in *dependency* folder.

```
redis
eigen3
hiredis
```

## Usage

1. Database preparation.

   1. Install Redis.

      ```
      cd redis-3.2.12
      make
      cd src
      sudo make install
      ```

   2. Download OPUS-DASF lookup tables and rotamer library data, which are hosted on [Baidu Drive](https://pan.baidu.com/s/1XxYz3HpYdpv_DPcZBsMgQA) with password `9dqu`. Also, they can be downloaded directly from [Here](http://ma-lab.rice.edu/dist/rota2_db.zip). Unzip *dump.zip* and put it into *redis-3.2.12*.


2. Install eigen3

   ```
   sudo apt install libeigen3-dev
   cd /usr/include/eigen3
   sudo cp Eigen/ .. -R
   ```
3. Install hiredis

   ```
   cd hiredis
   make
   sudo make install
   sudo ldconfig /usr/local/lib
   ```

4. Build OPUS-Rota2

   ```
   cd src
   mkdir build
   cmake .
   make
   cp rota2 ../
   ```
 
5. Run Redis. 
   ```
   cd /home/redis-3.2.12
   redis-server redis.conf
   ```   

   This will take approximately 1min until *"The server is now ready to accept connections on port 6379"* appeared in the console. 
 
4. Run OPUS-Rota2.

   Set the parameters in *rota2.ini*. If you want to use OPUS-Rota2i, please set `optimized=0`, if you want to use OPUS-Rota2, please set `optimized=1`.


