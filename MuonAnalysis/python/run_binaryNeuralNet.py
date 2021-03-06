import pandas as pd
import numpy as np

from DATA import *
from NN import evaluateSubset
from NN import NN
import sys
from make_bench import benchmark_sample
#initilization of datasets and model variables
#dypath='/home/t3-ku/janguian/storeUser/malazaro/TrainSetDYJets.root'
# dypath='/home/t3-ku/janguian/CMSSW_10_6_11_patch1/src/KUSoftMVA/MuonAnalysis/test/OutputFiles/DYJetsToLL2018_MINI_numEvent100000.root'
# qcdpath='/home/t3-ku/janguian/CMSSW_10_6_11_patch1/src/KUSoftMVA/MuonAnalysis/test/OutputFiles/QCD_pt_600to800_2018_MINI_numEvent100000.root'
#ttpath='/home/t3-ku/janguian/storeUser/malazaro/TrainSetTTJets.root'
# ttpath='/home/t3-ku/janguian/CMSSW_10_6_11_patch1/src/KUSoftMVA/MuonAnalysis/test/OutputFiles/TTJets2018_MINI_numEvent100000.root'

#high stats
dypath='/home/t3-ku/mlazarov/softMVA/CMSSW_10_6_11_patch1/src/KUSoftMVA/MuonAnalysis/data/Train_dyjets.root'
qcdpath='/home/t3-ku/mlazarov/softMVA/CMSSW_10_6_11_patch1/src/KUSoftMVA/MuonAnalysis/data/Train_qcd.root'
ttpath='/home/t3-ku/mlazarov/softMVA/CMSSW_10_6_11_patch1/src/KUSoftMVA/MuonAnalysis/data/Train_ttjets.root'

#T_dypath='/home/t3-ku/janguian/storeUser/malazaro/TestSetDYJets.root'
# T_dpath='/home/t3-ku/janguian/CMSSW_10_6_11_patch1/src/KUSoftMVA/MuonAnalysis/test/OutputFiles/DYJetsToLL2018_MINI_numEvent100000.root'
# T_qcdpath='/home/t3-ku/janguian/CMSSW_10_6_11_patch1/src/KUSoftMVA/MuonAnalysis/test/OutputFiles/QCD_pt_600to800_2018_MINI_numEvent100000.root'
# T_ttpath='/home/t3-ku/janguian/CMSSW_10_6_11_patch1/src/KUSoftMVA/MuonAnalysis/test/OutputFiles/TTJets2018_MINI_numEvent100000.root'
#T_ttpath='/home/t3-ku/janguian/storeUser/malazaro/TestSetTTJets.root'

#high stats
T_dypath='/home/t3-ku/mlazarov/softMVA/CMSSW_10_6_11_patch1/src/KUSoftMVA/MuonAnalysis/data/Test_dyjets.root'
T_qcdpath='/home/t3-ku/mlazarov/softMVA/CMSSW_10_6_11_patch1/src/KUSoftMVA/MuonAnalysis/data/Test_qcd.root'
T_ttpath='/home/t3-ku/mlazarov/softMVA/CMSSW_10_6_11_patch1/src/KUSoftMVA/MuonAnalysis/data/Test_ttjets.root'



# model_vars = ['Muon_pt','Muon_eta','Muon_chi2LocalMomentum',
# 'Muon_chi2LocalPosition','Muon_trkRelChi2','Muon_trkKink','Muon_glbKink',
# 'Muon_segmentCompatibility','Muon_timeAtIpInOutErr','Muon_innerTrackNormalizedChi2',
# 'Muon_innerTrackValidFraction','Muon_nTrackerLayersWithMeasurement',
# 'Muon_outerTrackCharge','Muon_innerTrackCharge',
# 'Muon_pfRelIso03_chg','Muon_pfRelIso03_all',
# 'Muon_isGood','Muon_isHighPurity','Muon_nPixelLayers','Muon_miniPFRelIso_chg','Muon_miniPFRelIso_all', 'Muon_looseId', 'Muon_softId', 'Muon_softMvaId' ]


train_vars = ['Muon_pt','Muon_eta','Muon_chi2LocalMomentum',
'Muon_chi2LocalPosition','Muon_trkRelChi2','Muon_trkKink','Muon_glbKink',
'Muon_segmentCompatibility','Muon_timeAtIpInOutErr','Muon_innerTrackNormalizedChi2',
'Muon_innerTrackValidFraction','Muon_nTrackerLayersWithMeasurement',
'Muon_outerTrackCharge','Muon_innerTrackCharge',
'Muon_pfRelIso03_chg','Muon_pfRelIso03_all',
'Muon_isGood','Muon_isHighPurity','Muon_nPixelLayers','Muon_miniPFRelIso_chg','Muon_miniPFRelIso_all']

outPath = '/home/t3-ku/mlazarov/softMVA/CMSSW_10_6_11_patch1/src/KUSoftMVA/MuonAnalysis'

eval_tag = sys.argv[1] # input string for tagging output files 

#quick and dirty sample all
mx = 999999999999

######################################################
####################MODEL 5###########################
print("\nBegin Model 5")

dymu, dyU, dypi, dyk, dyp = 10000, 2000, 2000, 2000, 2000
qmu, qU, qpi, qk, qp = 10000, 2000, 2000, 2000, 2000
tmu, tU, tpi, tk, tp = 4000, 2000, 2000, 2000, 2000

Tdymu, TdyU, Tdypi, Tdyk, Tdyp = 100000, 25000, 25000, 25000, 25000
Tqmu, TqU, Tqpi, Tqk, Tqp = 100000, 25000, 25000, 25000, 25000
Ttmu, TtU, Ttpi, Ttk, Ttp = 100000, 25000, 25000, 25000, 25000




dataset_DY = DATA(dypath,"Drell-Yan",train_vars)
T_dataset_DY = DATA(T_dypath,"TEST_Drell-Yan",train_vars)
# T_fulldysample= pd.concat(T_dataset_DY.sample(['mu','U','pi','k','p' ],[mx,mx,mx,mx,mx]) )
#
# dataset_DY.report()
# mdysample = dataset_DY.sample(['mu','U','pi','k','p' ],[dymu,dyU,dypi,dyk,dyp])
# print(len(mdysample))
# del dataset_DY

dataset_TT = DATA(ttpath, "TTJets",train_vars)
T_dataset_TT = DATA(T_ttpath,"TEST_ttJets",train_vars)
# dataset_TT.report()
# mttsample = dataset_TT.sample(['mu','U','pi','k','p'],[tmu,tU,tpi,tk,tp])
# del dataset_TT

dataset_QCD = DATA(qcdpath, "QCD",train_vars)
T_dataset_QCD = DATA(qcdpath,"TEST_QCD",train_vars)
# dataset_QCD.report()
# mqcdsample = dataset_QCD.sample(['mu','U','pi','k','p'],[qmu,qU,qpi,qk,qp])
# del dataset_QCD

mdict = {13: [1,0], 999: [0,1], 211:[0,1], 321:[0,1], 2212:[0,1]}
bdict = {'mu': [1,0], 'U':[0,1]}


modelDesc = "Model trained only on true muons vs unmatched with non muons EXCLUDING electrons in both test and in training, binary classification"

m = NN("model5", modelDesc, train_vars,mdict,eval_tag)

lastChunk = 10

## each chunk is one batch to train the NN on
## for each dataframe in the different physics processes do training for NN preprocessing
for chunk, (dy, tt, qcd) in enumerate(zip(dataset_DY.dfs, dataset_TT.dfs, dataset_QCD.dfs)):
	if chunk > lastChunk: #reading data in 100 MB chunks, 10*100 = 1 GB/process
		break
	print('chunk #', chunk)
#	print('dy',type(dy),dy.head())
	dy = reportAndSample(dy,dataset_DY.name, ['mu','U','pi','k','p' ],[dymu,dyU,dypi,dyk,dyp])
	tt = reportAndSample(tt,dataset_TT.name, ['mu','U','pi','k','p'],[tmu,tU,tpi,tk,tp])
	qcd = reportAndSample(qcd,dataset_QCD.name, ['mu','U','pi','k','p'],[qmu,qU,qpi,qk,qp])

	trainingChunk = pd.concat([dy,tt,qcd])
#	print('trainingChunk',trainingChunk.head())
	x_train, y_train, pt_train = prepareSet(trainingChunk,mdict)
	

	#use randomly initialized weights for first chunk
	if chunk == 0:
		m.trainNetwork(x_train,y_train, pt_train)
	else: #set weights of model from previous chunk
		weights = m.model.get_weights()
		m.model.set_weights(weights)
		m.trainNetwork(x_train,y_train, pt_train,weights)

dy = reportAndSample(dataset_DY.dfs[lastChunk+1],dataset_DY.name, ['mu','U','pi','k','p' ],[dymu,dyU,dypi,dyk,dyp])
tt = reportAndSample(dataset_TT.dfs[lastChunk+1],dataset_TT.name, ['mu','U','pi','k','p'],[tmu,tU,tpi,tk,tp])
qcd = reportAndSample(dataset_QCD.dfs[lastChunk+1],dataset_QCD.name, ['mu','U','pi','k','p'],[qmu,qU,qpi,qk,qp])
trainingChunk = pd.concat([dy,tt,qcd])

x_test,y_test,pt_test = prepareSet(trainingChunk,mdict)
# # #evaluate on last memChunk test sets
m.evaluateNetwork(outPath,x_test,y_test,pt_test)

del dataset_DY
del dataset_TT
del dataset_QCD

#evaluate on separate test sets
#create subsets for evaluation of network
T_dataset_DY.dfs = pd.concat(T_dataset_DY.dfs)
T_dataset_TT.dfs = pd.concat(T_dataset_TT.dfs)
T_dataset_QCD.dfs = pd.concat(T_dataset_QCD.dfs)

dyTest = reportAndSample(T_dataset_DY.dfs,format("Full Test "+T_dataset_DY.name), ['mu','U','pi','k','p' ],[mx,mx,mx,mx,mx])

ttTest = reportAndSample(T_dataset_TT.dfs,format("Full Test "+T_dataset_TT.name), ['mu','U','pi','k','p'],[mx,mx,mx,mx,mx])


qcdTest = reportAndSample(T_dataset_QCD.dfs,format("Full Test "+T_dataset_QCD.name), ['mu','U','pi','k','p'],[mx,mx,mx,mx,mx])


sub_dyTest = reportAndSample(T_dataset_DY.dfs,format("Sub Test "+T_dataset_DY.name), ['mu','U','pi','k','p' ],[Tdymu,TdyU,Tdypi,Tdyk,Tdyp])
sub_ttTest = reportAndSample(T_dataset_TT.dfs,format("Sub Test "+T_dataset_TT.name), ['mu','U','pi','k','p' ],[Ttmu,TtU,Ttpi,Ttk,Ttp])
sub_qcdTest = reportAndSample(T_dataset_QCD.dfs,format("Sub Test "+T_dataset_QCD.name), ['mu','U','pi','k','p' ],[Tqmu,TqU,Tqpi,Tqk,Tqp])


fullcombinedTest = pd.concat([sub_dyTest, sub_ttTest, sub_qcdTest])

x_testDY,y_testDY,pt_testDY = prepareSet(dyTest,mdict)
x_testTT,y_testTT,pt_testTT = prepareSet(ttTest,mdict)
x_testQCD,y_testQCD,pt_testQCD = prepareSet(qcdTest,mdict)
x_testCOMB,y_testCOMB,pt_testCOMB = prepareSet(fullcombinedTest,mdict)

del T_dataset_DY
del T_dataset_QCD
del T_dataset_TT

print("evaluating full DY")
evaluateSubset(m, y_testDY, x_testDY, pt_testDY, "DY",outPath)
print("\n")
print("evaluating full TT")
evaluateSubset(m, y_testTT, x_testTT, pt_testTT, "TT", outPath)
print("\n")
print("evaluating full QCD")
evaluateSubset(m,y_testQCD, x_testQCD, pt_testQCD, "QCD", outPath)
print("\n")
print("evaluating full combined")
evaluateSubset(m, y_testCOMB, x_testCOMB, pt_testCOMB, "COMB", outPath)


del dyTest
del ttTest
del qcdTest



# T_dataset_DY = DATA(dypath,"TEST_Drell-Yan")
# T_dataset_DY.report()
# T_fulldysample= pd.concat(T_dataset_DY.sample(['mu','U','pi','k','p' ],[mx,mx,mx,mx,mx]) )
# T_subdysample= pd.concat(T_dataset_DY.sample(['mu','U','pi','k','p' ],[dymu,dyU,dypi,dyk,dyp]) )
# del T_dataset_DY
# #benchmark set
# fulldy_x, fulldy_y, fulldy_pt = prepareBenchSet( T_fulldysample, model_vars, mdict)
# benchmark_sample( fulldy_x, fulldy_y, fulldy_pt, bdict, "DYfullB" )

# #special test set for model
# x_test1, y_test1, pt_test1 = prepareBenchSet(T_fulldysample,train_vars, mdict)
# del T_fulldysample

# T_dataset_QCD = DATA(qcdpath, "TEST_QCD")
# T_dataset_QCD.report()
# T_fullqcdsample=pd.concat(T_dataset_QCD.sample(['mu','U','pi','k','p'],[mx,mx,mx,mx,mx]) )
# T_subqcdsample= pd.concat(T_dataset_QCD.sample(['mu','U','pi','k','p'],[qmu,qU,qpi,qk,qp]) )
# del T_dataset_QCD
# fullqcd_x, fullqcd_y, fullqcd_pt = prepareBenchSet( T_fullqcdsample, model_vars, mdict)
# benchmark_sample( fullqcd_x, fullqcd_y, fullqcd_pt, bdict, "QCDfullB")
# x_test3, y_test3, pt_test3 = prepareBenchSet(T_fullqcdsample,train_vars, mdict)
# del T_fullqcdsample


# T_dataset_TT = DATA(ttpath, "TEST_TTJets")
# T_dataset_TT.report()
# T_fullttsample= pd.concat(T_dataset_TT.sample(['mu','U','pi','k','p'],[mx,mx,mx,mx,mx]) )
# T_subttsample= pd.concat(T_dataset_TT.sample(['mu','U','pi','k','p'],[tmu,tU,tpi,tk,tp]) )
# del T_dataset_TT
# fulltt_x, fulltt_y, fulltt_pt = prepareBenchSet( T_fullttsample, model_vars, mdict)
# benchmark_sample( fulltt_x, fulltt_y, fulltt_pt, bdict, "TTfullB")
# x_test2, y_test2, pt_test2 = prepareBenchSet(T_fullttsample,train_vars, mdict)
# del T_fullttsample

# T_fullcombinedsample = pd.concat([T_subdysample, T_subqcdsample, T_subttsample])
# fullcom_x, fullcom_y, fullcom_pt = prepareBenchSet( T_fullcombinedsample, model_vars, mdict)
# benchmark_sample( fullcom_x, fullcom_y, fullcom_pt, bdict, "CombB")
# x_test4, y_test4, pt_test4 = prepareBenchSet(T_fullcombinedsample, train_vars, mdict)
# del T_fullcombinedsample


# mdysample = pd.concat(mdysample)
# mttsample = pd.concat(mttsample)
# mqcdsample = pd.concat(mqcdsample)
# trainingData = pd.concat([mdysample, mttsample, mqcdsample ])
# x_train, x_test, y_train, y_test, pt_train, pt_test  = prepareTrainingSet(trainingData, train_vars, mdict)
# m = NN(x_train, x_test, y_train, y_test, "model5", "Model trained only on true muons vs unmatched with non muons EXCLUDING electrons in both test and in training, binary classification", mdict, pt_train, pt_test, '')



#individual sample testing and evaluation
# print("evaluating full DY")
# evaluateSubset(m,m.model, y_test1, x_test1, pt_test1, "DY")
# print("evaluating full TT")
# evaluateSubset(m,m.model, y_test2, x_test2, pt_test2, "TT")
# print("evaluating full QCD")
# evaluateSubset(m,m.model, y_test3, x_test3, pt_test3, "QCD")
# print("evaluating full combined")
# evaluateSubset(m,m.model, y_test4, x_test4, pt_test4, "COMB")





sys.exit();
print("\n")
######################################################
####################MODEL 6###########################
# print("\nBegin Model 6")
# mdysample = dataset_DY.sample(['mu','pi','k','p' ],[7000,2000,2000,2000])
# mttsample = dataset_TT.sample(['mu','pi','k','p'],[7000,2000,2000,2000])
# mqcdsample = dataset_QCD.sample(['mu','pi','k','p'],[4000,2000,2000,2000])

# reportSample( mdysample )
# reportSample( mttsample )
# reportSample( mqcdsample )
# mdict = {13: [1,0], 211:[0,1], 321:[0,1], 2212:[0,1]}

# datatest = pd.concat([pd.concat(mdysample), pd.concat(mttsample), pd.concat(mqcdsample) ])
# x_train, x_test, y_train, y_test, pt_train, pt_test  = prepareTrainingSet(datatest, model_vars, mdict)

# m = NN(x_train, x_test, y_train, y_test, "model6", "Model trained on true muons vs all  non muons, EXCLUDING electrons in both test and in training, binary classification", mdict, pt_train, pt_test, eval_tag)

# print("\n")
# ######################################################
# ####################MODEL 7###########################
# print("\nBegin Model 7")
# mdysample = dataset_DY.sample(['mu','U','pi','k','p' ],[2000,2000,2000,2000,2000])
# mttsample = dataset_TT.sample(['mu','U','pi','k','p'],[2000,2000,2000,2000,2000])
# mqcdsample = dataset_QCD.sample(['mu','U','pi','k','p'],[2000,2000,2000,2000,2000])

# reportSample( mdysample )
# reportSample( mttsample )
# reportSample( mqcdsample )
# mdict = {13: [1,0,0,0,0],999:[0,1,0,0,0], 211:[0,0,1,0,0], 321:[0,0,0,1,0], 2212:[0,0,0,0,1]}

# datatest = pd.concat([pd.concat(mdysample), pd.concat(mttsample), pd.concat(mqcdsample) ])
# x_train, x_test, y_train, y_test, pt_train, pt_test  = prepareTrainingSet(datatest, model_vars, mdict)

# m = NN(x_train, x_test, y_train, y_test, "model7", "Model trained on all classes EXCLUDING electrons in both training and testing , classification of  most  labels", mdict, pt_train, pt_test, eval_tag)

# print("\n")












