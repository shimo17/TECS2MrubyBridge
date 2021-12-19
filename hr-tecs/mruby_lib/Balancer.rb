module EV3RT_TECS
    class Balancer < TECS::TsBalancer
        private 
        def initialize
            super "BridgeBalancer"
            init
        end
        @@instance = self.new
        public
        def self.control(forward, turn, gyro, offset, angle_l, angle_r, vlt)
            pwm_l = TECS::Int8Pointer.new(1)
            pwm_r = TECS::Int8Pointer.new(1)
            @@instance.control(forward, turn, gyro, offset, angle_l, angle_r, vlt, pwm_l, pwm_r)
            return pwm_l.value, pwm_r.value
        end
    end
end
