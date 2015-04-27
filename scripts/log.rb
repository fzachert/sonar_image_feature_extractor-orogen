require "orocos"
require "vizkit"
include Orocos

log = Log::Replay.open('/media/fabio/WINDOWS/LOGS/sauce14/blueview/blueview.1.log')

Orocos.run "sonar_image_feature_extractor::Task" =>"sife"   do
  sife = Orocos.name_service.get('sife')

  #auto connect
  log.blueview.frame.connect_to sife.sonar_image
  
  sife.debug_mode = :FEATURES
  sife.smooth_mode = :GAUSSIAN
  sife.blur = 9
  sife.sobel = 3
  sife.threshold = 0.5
  sife.cluster_min_size = 5
  sife.cluster_max_size = 50
  sife.cluster_noise = 3
  
  sife.configure
  sife.start
  
  Vizkit.display sife
  Vizkit.control log
  Vizkit.exec
end