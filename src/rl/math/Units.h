/**
 ******************************************************************************
 * @Description   :
 * @author        : AN Hao
 * @Date          : 24-11-1
 * @Version       : 0.0.1
 * @File          : Units.h
 ******************************************************************************
 */

#ifndef RL_SRC_RL_MATH_UNITS_H_
#define RL_SRC_RL_MATH_UNITS_H_

namespace rl {
namespace math {
/**
 * Values describing [base units](https://en.wikipedia.org/wiki/SI_base_unit)
 * and [derived units](https://en.wikipedia.org/wiki/SI_derived_unit) of the
 * [International System of
 * Units](https://en.wikipedia.org/wiki/International_System_of_Units).
 */
enum class Units {
  /**
   * Value used for describing dimensionless quantities.
   */
  none,
  /**
   * The [second](https://en.wikipedia.org/wiki/Second) (symbol **s**) is the
   * [SI base unit](https://en.wikipedia.org/wiki/SI_base_unit)
   * of [time](https://en.wikipedia.org/wiki/Time).
   */
  second,
  /**
   * The [meter](https://en.wikipedia.org/wiki/Meter) (symbol **m**) is the
   * [SI base unit](https://en.wikipedia.org/wiki/SI_base_unit)
   * of [length](https://en.wikipedia.org/wiki/Length).
   */
  meter,
  /**
   * The [kilogram](https://en.wikipedia.org/wiki/Kilogram) (symbol **kg**) is
   * the [SI base unit](https://en.wikipedia.org/wiki/SI_base_unit) of
   * [mass](https://en.wikipedia.org/wiki/Mass).
   */
  kilogram,
  /**
   * The [ampere](https://en.wikipedia.org/wiki/Ampere) (symbol **A**) is the
   * [SI base unit](https://en.wikipedia.org/wiki/SI_base_unit)
   * of [electric current](https://en.wikipedia.org/wiki/Electric_current).
   */
  ampere,
  /**
   * The [kelvin](https://en.wikipedia.org/wiki/Kelvin) (symbol **K**) is the
   * [SI base unit](https://en.wikipedia.org/wiki/SI_base_unit)
   * of [thermodynamic
   * temperature](https://en.wikipedia.org/wiki/Thermodynamic_temperature).
   */
  kelvin,
  /**
   * The [mole](https://en.wikipedia.org/wiki/Mole_%28unit%29) (symbol **mol**)
   * is the [SI base unit](https://en.wikipedia.org/wiki/SI_base_unit) of
   * [amount of substance](https://en.wikipedia.org/wiki/Amount_of_substance).
   */
  mole,
  /**
   * The [candela](https://en.wikipedia.org/wiki/Candela) (symbol **cd**) is the
   * [SI base unit](https://en.wikipedia.org/wiki/SI_base_unit)
   * of [luminous intensity](https://en.wikipedia.org/wiki/Luminous_intensity).
   */
  candela,
  /**
   * The [radian](https://en.wikipedia.org/wiki/Radian) (symbol **rad**) is the
   * [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit)
   * of [plane angle](https://en.wikipedia.org/wiki/Angle).
   */
  radian,
  /**
   * The [steradian](https://en.wikipedia.org/wiki/Radian) (symbol **sr**) is
   * the [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit) of
   * [solid angle](https://en.wikipedia.org/wiki/Solid_angle).
   */
  steradian,
  /**
   * The [hertz](https://en.wikipedia.org/wiki/Hertz) (symbol **Hz**) is the
   * [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit)
   * of [frequency](https://en.wikipedia.org/wiki/Frequency)
   * and is defined as s<sup>-1</sup>.
   */
  hertz,
  /**
   * The [newton](https://en.wikipedia.org/wiki/Newton_(unit)) (symbol **N**) is
   * the [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit) of
   * [force](https://en.wikipedia.org/wiki/Force) and is defined as kg &middot;
   * m &middot; s<sup>-2</sup>.
   */
  newton,
  /**
   * The [pascal](https://en.wikipedia.org/wiki/Pascal_(unit)) (symbol **Pa**)
   * is the [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit) of
   * [pressure](https://en.wikipedia.org/wiki/Pressure) and is defined as kg
   * &middot; m<sup>-1</sup> &middot; s<sup>-2</sup>.
   */
  pascals,
  /**
   * The [joule](https://en.wikipedia.org/wiki/Joule) (symbol **J**) is the
   * [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit)
   * of [energy](https://en.wikipedia.org/wiki/Energy)
   * and is defined as kg &middot; m<sup>-2</sup> &middot; s<sup>-2</sup>.
   */
  joule,
  /**
   * The [watt](https://en.wikipedia.org/wiki/Watt) (symbol **W**) is the
   * [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit)
   * of [power](https://en.wikipedia.org/wiki/Power_(physics))
   * and is defined as kg &middot; m<sup>-2</sup> &middot; s<sup>-3</sup>.
   */
  watt,
  /**
   * The [coulomb](https://en.wikipedia.org/wiki/Coulomb) (symbol **C**) is the
   * [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit)
   * of [electric charge](https://en.wikipedia.org/wiki/Electric_charge)
   * and is defined as s &middot; A.
   */
  coulomb,
  /**
   * The [volt](https://en.wikipedia.org/wiki/Volt) (symbol **V**) is the
   * [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit)
   * of [electric potential](https://en.wikipedia.org/wiki/Electric_potential),
   * [electric potential
   * difference](https://en.wikipedia.org/wiki/Electric_potential_difference),
   * and [electromotive
   * force](https://en.wikipedia.org/wiki/Electromotive_force) and is defined as
   * kg &middot; m<sup>2</sup> &middot; s<sup>-3</sup> &middot; A<sup>-1</sup>.
   */
  volt,
  /**
   * The [farad](https://en.wikipedia.org/wiki/Farad) (symbol **F**) is the
   * [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit)
   * of [electrical capacitance](https://en.wikipedia.org/wiki/Capacitance)
   * and is defined as kg<sup>-1</sup> &middot; m<sup>-2</sup> &middot;
   * s<sup>4</sup> &middot; A<sup>2</sup>.
   */
  farad,
  /**
   * The [ohm](https://en.wikipedia.org/wiki/Ohm) (symbol **&Omega;**) is the
   * [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit)
   * of [electrical
   * resistance](https://en.wikipedia.org/wiki/Electrical_resistance) and is
   * defined as kg &middot; m<sup>2</sup> &middot; s<sup>-3</sup> &middot;
   * A<sup>-2</sup>.
   */
  ohm,
  /**
   * The [siemens](https://en.wikipedia.org/wiki/Siemens_(unit)) (symbol **S**)
   * is the [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit) of
   * [electrical
   * conductance](https://en.wikipedia.org/wiki/Electric_conductance) and is
   * defined as kg<sup>-1</sup> &middot; m<sup>-2</sup> &middot; s<sup>3</sup>
   * &middot; A<sup>2</sup>.
   */
  siemens,
  /**
   * The [weber](https://en.wikipedia.org/wiki/Weber_(unit)) (symbol **Wb**) is
   * the [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit) of
   * [magnetic flux](https://en.wikipedia.org/wiki/Magnetic_flux) and is defined
   * as kg &middot; m<sup>2</sup> &middot; s<sup>-2</sup> &middot;
   * A<sup>-1</sup>.
   */
  weber,
  /**
   * The [tesla](https://en.wikipedia.org/wiki/Tesla_(unit)) (symbol **T**) is
   * the [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit) of
   * [magnetic flux
   * density](https://en.wikipedia.org/wiki/Magnetic_flux_density) and is
   * defined as kg &middot; s<sup>-2</sup> &middot; A<sup>-1</sup>.
   */
  tesla,
  /**
   * The [henry](https://en.wikipedia.org/wiki/Henry_(unit)) (symbol **H**) is
   * the [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit) of
   * [electrical inductance](https://en.wikipedia.org/wiki/Inductance) and is
   * defined as kg &middot; m<sup>2</sup> &middot; s<sup>-2</sup> &middot;
   * A<sup>-2</sup>.
   */
  henry,
  /**
   * The [degree Celsius](https://en.wikipedia.org/wiki/Degree_Celsius) (symbol
   * **&ordm;C**) is the [SI derived
   * unit](https://en.wikipedia.org/wiki/SI_derived_unit) referring to a
   * temperature on the Celsius scale and is defined as temperature relative to
   * 273.15 K.
   */
  celsius,
  /**
   * The [lumen](https://en.wikipedia.org/wiki/Lumen_(unit)) (symbol **lm**) is
   * the [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit) of
   * [luminous flux](https://en.wikipedia.org/wiki/Luminous_flux) and is defined
   * as cd &middot; sr.
   */
  lumen,
  /**
   * The [lux](https://en.wikipedia.org/wiki/Lux) (symbol **lx**) is the
   * [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit)
   * of [illuminance](https://en.wikipedia.org/wiki/Illuminance)
   * and is defined as m<sup>-2</sup> &middot; cd.
   */
  lux,
  /**
   * The [becquerel](https://en.wikipedia.org/wiki/Becquerel) (symbol **Bq**) is
   * the [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit) of
   * [radioactivity](https://en.wikipedia.org/wiki/Radioactivity) and is defined
   * as s<sup>-1</sup>.
   */
  becquerel,
  /**
   * The [gray](https://en.wikipedia.org/wiki/Gray_(unit)) (symbol **Gy**) is
   * the [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit) of
   * [absorbed dose](https://en.wikipedia.org/wiki/Absorbed_dose) of [ionising
   * radiation](https://en.wikipedia.org/wiki/Ionizing_radiation) and is defined
   * as m<sup>2</sup> &middot; s<sup>-2</sup>.
   */
  gray,
  /**
   * The [sievert](https://en.wikipedia.org/wiki/Sievert) (symbol **Sv**) is the
   * [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit)
   * of [equivalent dose](https://en.wikipedia.org/wiki/Equivalent_dose)
   * of [ionising radiation](https://en.wikipedia.org/wiki/Ionizing_radiation)
   * and is defined as m<sup>2</sup> &middot; s<sup>-2</sup>.
   */
  sievert,
  /**
   * The [katal](https://en.wikipedia.org/wiki/Katal) (symbol **kat**) is the
   * [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit)
   * of [catalytic activity](https://en.wikipedia.org/wiki/Catalytic_activity)
   * and is defined as mol &middot; s<sup>-1</sup>.
   */
  katal,
  /**
   * The [square meter](https://en.wikipedia.org/wiki/Square_metre) (symbol
   * **m<sup>2</sup>**) is the [SI derived
   * unit](https://en.wikipedia.org/wiki/SI_derived_unit) of
   * [area](https://en.wikipedia.org/wiki/Area) and is defined as m<sup>2</sup>.
   */
  squareMeter,
  /**
   * The [cubic meter](https://en.wikipedia.org/wiki/Cubic_metre) (symbol
   * **m<sup>3</sup>**) is the [SI derived
   * unit](https://en.wikipedia.org/wiki/SI_derived_unit) of
   * [volume](https://en.wikipedia.org/wiki/Volume) and is defined as
   * m<sup>3</sup>.
   */
  cubicMeter,
  /**
   * The [meter per second](https://en.wikipedia.org/wiki/Metre_per_second)
   * (symbol **m &middot; s<sup>-1</sup>**) is the [SI derived
   * unit](https://en.wikipedia.org/wiki/SI_derived_unit) of both
   * [speed](https://en.wikipedia.org/wiki/Speed) and
   * [velocity](https://en.wikipedia.org/wiki/Velocity)
   * and is defined as m &middot; s<sup>-1</sup>.
   */
  meterPerSecond,
  /**
   * The [meter per second
   * squared](https://en.wikipedia.org/wiki/Metre_per_second_squared) (symbol
   * **m &middot; s<sup>-2</sup>**) is the [SI derived
   * unit](https://en.wikipedia.org/wiki/SI_derived_unit) of
   * [acceleration](https://en.wikipedia.org/wiki/Acceleration) and is defined
   * as m &middot; s<sup>-2</sup>.
   */
  meterPerSecondSquared,
  /**
   * The kilogram per square meter (symbol **kg &middot; m<sup>-2</sup>**) is
   * the [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit) of
   * [surface density](https://en.wikipedia.org/wiki/Surface_density) and is
   * defined as kg &middot; m<sup>-2</sup>.
   */
  kilogramPerSquareMeter,
  /**
   * The [kilogram per cubic
   * meter](https://en.wikipedia.org/wiki/Kilogram_per_cubic_metre) (symbol **kg
   * &middot; m<sup>-3</sup>**) is the [SI derived
   * unit](https://en.wikipedia.org/wiki/SI_derived_unit) of
   * [density](https://en.wikipedia.org/wiki/Density) and is defined as kg
   * &middot; m<sup>-3</sup>.
   */
  kilogramPerCubicMeter,
  /**
   * The [newton meter](https://en.wikipedia.org/wiki/Newton_metre) (symbol **N
   * &middot; m**) is the [SI derived
   * unit](https://en.wikipedia.org/wiki/SI_derived_unit) of
   * [torque](https://en.wikipedia.org/wiki/Torque) and is defined as kg
   * &middot; m<sup>2</sup> &middot; s<sup>-2</sup>.
   */
  newtonMeter,
  /**
   * The newton per meter (symbol **N &middot; m<sup>-1</sup>**) is the
   * [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit)
   * of [surface tension](https://en.wikipedia.org/wiki/Surface_tension)
   * and is defined as kg &middot; s<sup>-2</sup>.
   */
  newtonPerMeter,
  /**
   * The [radian per second](https://en.wikipedia.org/wiki/Radian_per_second)
   * (symbol **rad &middot; s<sup>-1</sup>**) is the [SI derived
   * unit](https://en.wikipedia.org/wiki/SI_derived_unit) of [angular
   * velocity](https://en.wikipedia.org/wiki/Angular_velocity) and is defined as
   * rad &middot; s<sup>-1</sup>.
   */
  radianPerSecond,
  /**
   * The [radian per second
   * squared](https://en.wikipedia.org/wiki/Radian_per_second_squared) (symbol
   * **rad &middot; s<sup>-2</sup>**) is the [SI derived
   * unit](https://en.wikipedia.org/wiki/SI_derived_unit) of [angular
   * acceleration](https://en.wikipedia.org/wiki/Angular_acceleration) and is
   * defined as rad &middot; s<sup>-2</sup>.
   */
  radianPerSecondSquared,
  /**
   * The [newton second](https://en.wikipedia.org/wiki/Newton_second) (symbol
   * **N &middot; s**) is the [SI derived
   * unit](https://en.wikipedia.org/wiki/SI_derived_unit) of
   * [impulse](https://en.wikipedia.org/wiki/Impulse_(physics)) and is defined
   * as kg &middot; m &middot; s<sup>-1</sup>.
   */
  newtonSecond,
  /**
   * The newton meter second (symbol **N &middot; m &middot; s**) is the
   * [SI derived unit](https://en.wikipedia.org/wiki/SI_derived_unit)
   * of [angular momentum](https://en.wikipedia.org/wiki/Angular_momentum)
   * and is defined as kg &middot; m<sup>2</sup> &middot; s<sup>-1</sup>.
   */
  newtonMeterSecond
};
}  // namespace math
}  // namespace rl

#endif  // RL_SRC_RL_MATH_UNITS_H_
