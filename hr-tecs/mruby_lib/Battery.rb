module EV3RT_TECS
    class Battery < TECS::TsBattery
        private
        def initialize()
            super "BridgeBattery"
        end
        @@instance = self.new
        public
        def self.mA
            @@instance.current_mA
        end
        def self.mV
            @@instance.voltage_mV
        end
    end
end
