# OPUS-Rota2

Side-chain modeling plays a critical role in protein structure prediction. However, in many current methods, balancing the speed and accuracy is still challenging. We introduce a new side-chain modeling method, OPUS-Rota2, which is tested on both 65-protein test set (DB65) in OPUS-Rota paper and 379-protein test set (DB379) in SCWRL4 paper. If the main chain is native, OPUS-Rota2 is more accurate than OPUS-Rota, SCWRL4 and OSCAR-star, but slightly less accurate than OSCAR-o. And if the main chain is non-native, OPUS-Rota2 is more accurate than any other method. Moreover, OPUS-Rota2 is significantly faster than any other method, in particular two orders of magnitude faster than OSCAR-o. Thus the combination of higher accuracy and speed of OPUS-Rota2 in modeling side chains on both native and non-native main chains makes OPUS-Rota2 a very useful tool in protein structure modeling.

## Test Sets

### Native Main Chain

We use both 65-protein test set (DB65) in OPUS-Rota paper and 379-protein test set (DB379) in SCWRL4 paper as our test sets. We clean the PDB files in these two test sets, and separate each clean set into two subsets, one of which contains main-chain atoms only and the other contains all atoms.

We remove *pdb2qol.ent* in DB379 for its incomplete main chain.

### Non-native Main Chain

To evaluate the performance of different side-chain modeling methods when the configurations of the main chains are non-native, we add random noise with various strengths to the main-chain torsional angles. We use 10 different levels of noise strength, i.e., the mean values of Gaussian are 1.0, and the standard deviations of them are (0.001, 0.003, 0.005, 0.008, 0.01, 0.013, 0.014, 0.015, 0.016, 0.02). Thus, we have 10 non-native test sets, each of them contains 437 proteins (combination of the proteins in DB65 and DB379). The corresponding average main-chain RMSD of 437 proteins (between the randomized structure and the native structure) at each noise level are (0.21, 0.57, 0.93, 1.48, 1.88, 2.38, 2.55, 2.74, 2.95, 3.68) angstroms.

### Download

The test sets we used are hosted on [Baidu Drive](https://pan.baidu.com/s/1NQ3mlVN2MqSbT8KdAK6OqQ) with password `jk29`.

## Performance

### Performance on Native Test Set

The accuracy of χ1 is defined as the percentage of residues whose predicted χ1 is no more than 40° from the native value, and the accuracy of χ(1+2) is defined as the percentage of residues for which both χ1 and χ2 are in 40° range compare to the native value. The same goes for the χ(1+2+3) and the χ(1+2+3+4) rows. For these indicators, the larger the better. The aRMSD row stands for the average RMSD between all atoms in predict residue and native residue, the smaller its value is, the better. Time stands for the average time for modeling each structure. 

|DB65|	SCWRL4|	OPUS-Rota	|OSCAR-star|	OSCAR-o|	OPUS-Rota2i|	OPUS-Rota2|
|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
|χ1	|0.86	|0.88|	0.89|	0.90|	0.89	|0.90|
|χ(1+2)|	0.68|	0.71|	0.72|	0.74	|0.74	|0.74|
|χ(1+2+3)|	0.41|	0.46|	0.47	|0.51|	0.50	|0.51|
|χ(1+2+3+4)|	0.30|	0.36|	0.35|	0.39	|0.38|	0.38|
|aRMSD|	0.67|	0.59|	0.58|	0.53|	0.55|	0.54|
|Time|	1.91|	2.98|	6.55|	583.00|	0.55	|0.98|

|DB65|	SCWRL4|	OPUS-Rota	|OSCAR-star|	OSCAR-o|	OPUS-Rota2i|	OPUS-Rota2|
|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
|χ1	|0.85	|0.86	|0.87	|0.88	|0.86|	0.87|
|χ(1+2)	|0.68	|0.69	|0.70	|0.73	|0.69|	0.71|
|χ(1+2+3)	|0.39	|0.41|	0.42|	0.47|	0.43|	0.45|
|χ(1+2+3+4)|	0.29	|0.31|	0.32|	0.37|	0.32|	0.33|
|aRMSD|	0.68|	0.64|	0.62|	0.57|	0.63|	0.61|
|Time	|2.13|	3.08|	6.35|	569.05|	0.54	|0.95|

### Performance on Non-native Test Set

The performance of different side-chain modeling methods on different non-native test sets. Three non-native test sets (each containing 437 proteins) are chosen for demonstration. Their corresponding average RMSD (aRMSD) values from the native structures are 0.93Å, 1.88Å and 3.68Å, respectively. Only the accuracy of χ1 is used as indicator. 

![fig1](./images/fig1.png?raw=true "fig1")

The performance of OPUS-Rota2 and OPUS-Rota2i on 10 different non-native test sets as a function of aRMSD.

![fig2](./images/fig1.png?raw=true "fig2")

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
