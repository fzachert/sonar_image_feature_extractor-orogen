require "orocos"
require "vizkit"
require './label_view.rb'
include Orocos


log = Log::Replay.open('/home/fabio/gemini.0.log')

Orocos.run "sonar_image_feature_extractor::LabelCreator" => "lc", "gemini_scan_converter::Task" =>"gem"  do
  
  Orocos.log_all
  
  lc = Orocos.name_service.get('lc')
  gem = Orocos.name_service.get('gem')

  gui = LabelCreation.new(lc, gem)
  gui.show
  
  
  #auto connect
  #auto connect
   log.gemini.frame.connect_to gem.frame
   gem.sonar_scan.connect_to lc.input_scans
#   
   gem.column = false
   gem.toogle = true
   
   gem.configure
   gem.start
   
  
  lc.debug_mode = :SMOOTHING
  lc.smooth_mode = :AVG
  lc.threshold_mode = :ADAPTIVE_MEAN
  lc.distance_mode = :EUKLIDIAN
  
  lc.blur = 3
  lc.threshold = 0.15
  lc.adaptive_threshold_neighborhood = 15  
  
  lc.cluster_min_size = 10
  lc.cluster_max_size = 1000
  lc.cluster_noise = 0.5
  
  
  lc.max_sonar_range = 16
  
  lc.configure
  lc.start  

  
  #Vizkit.display lc
  Vizkit.display lc
  Vizkit.control log
  Vizkit.exec
end