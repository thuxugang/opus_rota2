# OPUS-Rota2

## Dependency

```
Docker 18.09.7
```

## Usage

1. Download OPUS-Rota2 docker image.

   The docker image we used is hosted on [Baidu Drive](https://pan.baidu.com/s/1NQ3mlVN2MqSbT8KdAK6OqQ) with password `jk29`.

2. Docker image preparation.
   ```
   cat opus_rota2_docker* | tar xvz
   docker load -i opus_rota2.tar
   docker run -it --name rota2 opus_rota2:1.0
   ```
   
3. Run Redis. 
   ```
   cd /home/redis-3.2.12
   nohup redis-server redis.conf > nohup.out &
   ```   

   This will take approximately 1min until "The server is now ready to accept connections on port 6379" appeared in *nohup.out*. 
 
4. Run OPUS-Rota2.

   Set the parameters in *rota2.ini*. If you want to use OPUS-Rota2i, please set `optimized=0`, if you want to use OPUS-Rota2, please set `optimized=1`.

## Notice

The bottleneck of OPUS-Rota2's speed is the database query efficiency. Therefore, we use Redis for higher speed. However, since the database like MongoDB use cache to accelerate the query efficiency for repetitive keys, if you build the specific protein side chain 
recursively (maybe this kind of circumstance is the majority), the influence of database query efficiency would be reduced.

***If you want to include OPUS-Rota2 in your code, please download the source code and complie it. The source code is under the source branch.***

## To Do List
- [ ] Build on-line lookup tables server and remove the database dependcy in stand-alone version.

## Reference 
```bibtex
@article{xu2019opus,
  title={OPUS-Rota2: An Improved Fast and Accurate Side-chain Modeling Method},
  author={Xu, Gang and Ma, Tianqi and Du, Junqing and Wang, Qinghua and Ma, Jianpeng},
  journal={Journal of chemical theory and computation},
  year={2019},
  publisher={ACS Publications}
}
```
