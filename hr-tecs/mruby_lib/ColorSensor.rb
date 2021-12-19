module EV3RT_TECS
    class ColorSensor < TECS::TsColorSensor
        @@color_hash={0 =>:none, 1 =>:black, 2 =>:blue, 3 =>:green,
            4 =>:yellow, 5 =>:red, 6 =>:white, 7 => :brown}
        def initialize( port )
            if($port_hash[port] != nil)
                LCD.error_puts "ColorSensor::#{$port_hash[port]} has used #{port}"
                raise "ColorSensor::#{$port_hash[port]} has used #{port}"
            else
                $port_hash[port] = "ColorSensor"
            end
            puts "call ColorSensor, for #{port}"
            @port = port
            case port
            when :port_1 then
                realname = "BridgeColorSensor1"
            when :port_2 then
                realname = "BridgeColorSensor2"
            when :port_3 then
                realname = "BridgeColorSensor3"
            when :port_4 then
                realname = "BridgeColorSensor4"
            else
                LCD.error_puts "#{port} is unknown port for ColorSensor."
                raise "#{port} is unknown port for ColorSensor."
            end
            super realname
            initializePort
        end
        # カラーセンサの値を取得
        # @return
        def reflect
            getReflect
        end
        def ambient
            getAmbient
        end
        # カラーセンサの色の種類を取得
        # @return
        # :none, :black, :blue, :green,
        # :yellow, :red, :white,:brown}
        def color
            @@color_hash[getColor]
        end
        
        def black?
            color == :black
        end
        def blue?
            color == :bule
        end
        def green?
            color == :green
        end
        def yellow?
            color == :yellow
        end
        def red?
            color == :red
        end
        def white?
            color == :white
        end
        def brown?
            color == :brown
        end
    end
end
