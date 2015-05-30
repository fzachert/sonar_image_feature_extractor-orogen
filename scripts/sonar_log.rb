require "orocos"
require "vizkit"
include Orocos


log = Log::Replay.open('/home/fabio/gemini.0.log')

Orocos.run "sonar_image_feature_extractor::SonarBeamProcessing" =>"sife", "gemini_scan_converter::Task" =>"gem"   do
  sife = Orocos.name_service.get('sife')
  gem = Orocos.name_service.get('gem')

  #auto connect
  log.gemini.frame.connect_to gem.frame
  gem.sonar_scan.connect_to sife.sonar_image
  
  gem.column = false
  gem.toogle = true
  
  sife.debug_mode = :SMOOTHING
  sife.smooth_mode = :AVG
  sife.threshold_mode = :ADAPTIVE_MEAN
  sife.distance_mode = :EUKLIDIAN
  
  sife.blur = 3
  sife.threshold = 0.15
  sife.adaptive_threshold_neighborhood = 15  
  
  sife.cluster_min_size = 20
  sife.cluster_max_size = 1000000
  sife.cluster_noise = 0.5
  
  
  sife.max_sonar_range = 16
  
  sife.configure
  sife.start
  
  gem.configure
  gem.start
  
  Vizkit.display sife
  Vizkit.display gem
  Vizkit.control log
  Vizkit.exec
end