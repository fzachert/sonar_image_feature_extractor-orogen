require "vizkit"
require "orocos"

class LabelCreation 

  def initialize(label_task, sonar_task)
    puts "Init"
    #super
    puts "Init"
    
    @label_task = label_task
    @sonar_log = sonar_task

    @window = Vizkit.load(File.join(File.dirname(__FILE__),"label.ui"))
    
    @image_connection = @sonar_log.sonar_scan.connect_to @window.SonarView, :type=>:buffer,:size=>1
    
    @window.SonarView.setMaxRange(16)
    
    @x_label = 0
    @y_label = 0  
    
    puts "Init end"

    @window.DoubleSpinBoxX.connect(SIGNAL('valueChanged(double)')) do |value|
        puts "Spin box x"
      
	@label_task.label_x = value
	@x_label = value
	
	@window.SonarView.setLabelX(value);
	
#         @line1.setPosX(x - 640*Math.sin(sample.angle))
#         @line1.setPosY(y - 640*Math.cos(sample.angle))	
	
    end

    @window.DoubleSpinBoxY.connect(SIGNAL('valueChanged(double)')) do |value|
        puts "Spin box y"
      
	@label_task.label_y = value
	@y_label = value
	
	@window.SonarView.setLabelY(value);
	
    end
    
    @window.DoubleSpinBoxLabel.connect(SIGNAL('valueChanged(double)')) do |value|
        puts "Spin box label"
      
	@label_task.id = value
	
    end
    
    @window.DoubleSpinBoxRange.connect(SIGNAL('valueChanged(double)')) do |value|
        puts "Spin box range"
      
	@label_task.id = value
	@window.SonarView.setMaxRange(16)
    end
    
    

  end


  def show
      @window.show
      puts "Show"
  end
end

