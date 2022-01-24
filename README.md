# Checks for multi-phase variables available on ANSYS Fluent UDFs

We use a lot of different approaches to consult the case multi-phase configuration and
multi-phase setup details. Here I show and test a few more direct options available at
the `sg_mphase.h` header file.

The main entrance point to these new variables is the `sg_mphase` variable, its value is
defined by an enumeration defined at the `sg_mphase.h` header file as:

```c
typedef enum
{
  MP_OFF = 0,       /* same as FALSE */
  MP_VOF,           /* corresponds to boolean mp_vof    */
  MP_HOMOGENEOUS,   /*                        mp_hom    */
  MP_DRIFT_FLUX,    /*                        mp_drift  */
  MP_MULTI_FLUID,   /*                        mp_mfluid */
  MP_MODEL_MAX
} MP_Model;

extern FLUENT_EXPORT MP_Model sg_mphase;
```

So, the `sg_mphase` variable indicates the current case multi-phase approach being used.

Additional variables listed on the same file (not in this order, but all are defined at
the same block) are:

```c
extern FLUENT_EXPORT cxboolean mp_vof;
extern FLUENT_EXPORT cxboolean mp_mixture;
extern FLUENT_EXPORT cxboolean mp_hom;
extern FLUENT_EXPORT cxboolean mp_drift;
extern FLUENT_EXPORT cxboolean mp_mfluid;
```

All these variables are (threated as) Boolean flags for:

- `mp_vof` - Volume of Fluid
- `mp_mixture` - multiphase approach with a mixture (main) velocity field being used
- `mp_hom` - mixture model without slip-velocity
- `mp_drift` - mixture with slip-velocity
- `mp_mfluid` - Eulerian multi-fluid

Another interesting variable is the `mp_n` defined at the same header file. This variable has an integer value and is used to store the number of phases being used in
the current setup.

```c
extern FLUENT_EXPORT int mp_n;
```

Below are the outputs of the test UDF showing the usage and contents of these variables.

## Single-phase

```scheme
...multi-phase option via the `sg_mphase` variable:
     ...single-phase setup.

...multi-phase Boolean variables:
     ...`mp_vof` variable = 0
     ...`mp_mixture` variable = 0
     ...`mp_hom` variable = 0
     ...`mp_drift` variable = 0
     ...`mp_mfluid` variable = 0
     ...`mp_n` variable = 0
```

## VOF (volume-of-fluid)

```scheme
...multi-phase option via the `sg_mphase` variable:
    ...VOF multi-phase setup.

...multi-phase Boolean variables:
    ...`mp_vof` variable = 1
    ...`mp_mixture` variable = 1
    ...`mp_hom` variable = 0
    ...`mp_drift` variable = 0
    ...`mp_mfluid` variable = 0
    ...`mp_n` variable = 2
```

## Eulerian

```scheme
...multi-phase option via the `sg_mphase` variable:
    ...Eulerian multi-fluid multi-phase setup.

...multi-phase Boolean variables:
    ...`mp_vof` variable = 0
    ...`mp_mixture` variable = 0
    ...`mp_hom` variable = 0
    ...`mp_drift` variable = 0
    ...`mp_mfluid` variable = 1
    ...`mp_n` variable = 3
```

## Mixture

```scheme
...multi-phase option via the `sg_mphase` variable;
    ...Mixture homogeneous multi-phase setup.

...multi-phase Boolean variables;
    ...`mp_vof` variable = 0
    ...`mp_mixture` variable = 1
    ...`mp_hom` variable = 1
    ...`mp_drift` variable = 0
    ...`mp_mfluid` variable = 0
    ...`mp_n` variable = 4
```

## Mixture + slip velocity

```scheme
...multi-phase option via the `sg_mphase` variable:
    ...Mixture drift-flux multi-phase setup.

...multi-phase Boolean variables:
    ...`mp_vof` variable = 0
    ...`mp_mixture` variable = 1
    ...`mp_hom` variable = 0
    ...`mp_drift` variable = 1
    ...`mp_mfluid` variable = 0
    ...`mp_n` variable = 4
```

So we can use these variables and the enumeration with confidence that they will contain
the expected (correct) values.
