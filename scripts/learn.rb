require "orocos"
require "vizkit"
include Orocos


log = Log::Replay.open('lc.2.log')

Orocos.run "sonar_image_feature_extractor::SVMTraining" => "svmt", :valgrind =>false  do
  svmt = Orocos.name_service.get('svmt')
  
  #auto connect
  log.lc.connect_to svmt, :type => :buffer,:size => 500

  svmt.timeout = 5
  conf = svmt.svm_config
  conf.svm_path = "svm.sav"#"/home/fabio/rock/cuslam/orogen/sonar_image_feature_extractor/scripts/config/svm"
  conf.svm_type = :C_SVC
  conf.kernel_type = :RBF
  conf.kernel_degree = 5
  conf.rbf_gamma = 16384
  conf.coef0 = 1   
  
  conf.cache_size = 10
  conf.stopping_eps = 0.001
  conf.C = 16
  #conf.weights = [1, 1]
  #conf.weight_labels = [-1.0, 1.0]
  
  conf.use_shrinking = 1
  conf.use_probability = 0  
  conf.learn = true
  
  conf.cross_validation = true
#   conf.number_of_folds = 5
#   conf.start_gamma_exp = 0
#   conf.end_gamma_exp = 0
#   conf.start_C_exp = -5
#   conf.end_C_exp = 15  
   conf.number_of_folds = 5
   conf.start_gamma_exp = -5
   conf.end_gamma_exp = 15
   conf.start_C_exp = -5
   conf.end_C_exp = 15
  
  svmt.svm_config = conf
  
  svmt.configure
  svmt.start
  
  
  Vizkit.display svmt
  #Vizkit.control log
  log.run
  Vizkit.exec
end